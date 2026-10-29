#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <climits>
#include <unordered_set>

using namespace std;
using ll = long long;
using ull = unsigned long long;

// ===================== パラメータ =====================
const int    DEPTH         = 4;        // 先読みの深さ（1 = その手の点数だけ, 2 = 元のコードと同じ1手先読み）
const int    BEAM_M        = 10;       // 深さ3以上のとき、各階層で展開する上位の手の数
const int    STACK_LIMIT   = 8;        // 移動後のスタック上限
const ll     STUCK_PENALTY = 100000;   // 詰み局面のペナルティ
const double TIME_LIMIT_MS = 180000;     // 制限時間(ms)。これの8割を超えたら深さ1に落とす
const int    MAX_TURN      = 100000;   // 念のための手数上限

// ===================== 盤面 =====================
int N, K, NN, S;
const int dirX[4] = {-1, 0, 1, 0}, dirY[4] = {0, -1, 0, 1};
const char dirCh[4] = {'L', 'U', 'R', 'D'};

struct Cell {
    bool ground = false;
    int hole = -1;              // 巣の色（なければ -1）
    vector<int> st;             // スライムID（back が一番上）
};
struct Slime { int y, x, c, k; bool remain; };

vector<Cell>  cells;            // cells[y*N+x]
vector<Slime> slimes;
vector<int>   holeCell;         // 色 c の巣のマス番号
vector<int>   D;                // D[a*NN+b] : マス a から b への最短距離（到達不能は -1）
int remainCnt = 0;              // 盤面に残っているスライム数

inline int  dist(int a, int b) { return D[a * NN + b]; }
inline bool inField(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N && cells[y * N + x].ground;
}

// ===================== 手 =====================
struct Hand { int y, x, k, d, j; };     // (y,x) の下から k 匹を残し、方向 d に距離 j 飛ぶ

inline int destCell(const Hand& h) {
    return (h.y + dirY[h.d] * h.j) * N + (h.x + dirX[h.d] * h.j);
}

// 指した手の記録（元のコードの hash と同じ要素：位置, k, 方向, 一緒に動く一番下のスライム）
unordered_set<ll> played;
inline ll handHash(const Hand& h) {
    int bottomId = cells[h.y * N + h.x].st[h.k];
    return ((((ll)(h.y * N + h.x) * 16 + h.k) * 4 + h.d) * S + bottomId);
}

// 候補手の列挙
//   maxDist  : 各色で巣から一番遠いスライムだけを対象にする
//   memoBlock: 過去に指した手を除外する
//   retreat  : 巣から遠ざかる手も許可する（詰み脱出用）
void makeHand(vector<Hand>& out, bool maxDist, bool memoBlock, bool retreat) {
    out.clear();
    static vector<int> disMax;
    if (maxDist) {
        disMax.assign(K, 0);
        for (auto& s : slimes) if (s.remain) {
            int d = dist(s.y * N + s.x, holeCell[s.c]);
            if (disMax[s.c] < d) disMax[s.c] = d;
        }
    }
    for (auto& s : slimes) {
        if (!s.remain) continue;
        int cur = s.y * N + s.x, hc = holeCell[s.c];
        int dcur = dist(cur, hc);
        if (maxDist && dcur != disMax[s.c]) continue;
        int base = (int)cells[cur].st.size() - s.k;      // 一緒に動く匹数
        for (int d = 0; d < 4; d++) {
            for (int j = 1; j <= s.k + 1; j++) {
                int ny = s.y + dirY[d] * j, nx = s.x + dirX[d] * j;
                if (!inField(ny, nx)) break;
                int nc = ny * N + nx;
                if ((int)cells[nc].st.size() + base > STACK_LIMIT) continue;
                if (!retreat && !(dcur > dist(nc, hc))) continue;
                Hand h{s.y, s.x, s.k, d, j};
                if (memoBlock && played.count(handHash(h))) continue;
                out.push_back(h);
            }
        }
    }
}

// ===================== move / undo =====================
struct UndoRec {
    Hand h;
    int m, rs, rd;              // 動かした匹数 / 元マスで消えた数 / 行き先で消えた数
    int remS[32], remD[32];     // 消えたスライムのID（消えた順）
};

// 巣の上で色が一致するスライムを上から消す
inline void removeAtHole(int cell, int* rem, int& rcnt) {
    auto& C = cells[cell];
    while (C.hole >= 0 && !C.st.empty() && slimes[C.st.back()].c == C.hole) {
        int id = C.st.back(); C.st.pop_back();
        slimes[id].remain = false;
        rem[rcnt++] = id;
    }
}

UndoRec doMove(const Hand& h) {
    UndoRec u; u.h = h; u.rs = u.rd = 0;
    int sc = h.y * N + h.x, tc = destCell(h);
    int ty = tc / N, tx = tc % N;
    auto& Sv = cells[sc].st; auto& Tv = cells[tc].st;

    u.m = (int)Sv.size() - h.k;
    while ((int)Sv.size() > h.k) {              // 上から順に移す（順序は反転する）
        int id = Sv.back(); Sv.pop_back();
        slimes[id].y = ty; slimes[id].x = tx; slimes[id].k = (int)Tv.size();
        Tv.push_back(id);
    }
    removeAtHole(tc, u.remD, u.rd);
    removeAtHole(sc, u.remS, u.rs);
    remainCnt -= u.rs + u.rd;
    return u;
}

void undoMove(const UndoRec& u) {              // doMove の逆順で戻す
    const Hand& h = u.h;
    int sc = h.y * N + h.x, tc = destCell(h);
    int ty = tc / N, tx = tc % N;
    auto& Sv = cells[sc].st; auto& Tv = cells[tc].st;

    for (int i = u.rs - 1; i >= 0; i--) {
        int id = u.remS[i];
        slimes[id].remain = true; slimes[id].y = h.y; slimes[id].x = h.x;
        slimes[id].k = (int)Sv.size(); Sv.push_back(id);
    }
    for (int i = u.rd - 1; i >= 0; i--) {
        int id = u.remD[i];
        slimes[id].remain = true; slimes[id].y = ty; slimes[id].x = tx;
        slimes[id].k = (int)Tv.size(); Tv.push_back(id);
    }
    for (int i = 0; i < u.m; i++) {
        int id = Tv.back(); Tv.pop_back();
        slimes[id].y = h.y; slimes[id].x = h.x;
        slimes[id].k = (int)Sv.size(); Sv.push_back(id);
    }
    remainCnt += u.rs + u.rd;
}

// ===================== 局面ハッシュ（無限ループ防止） =====================
vector<ull> zob;                               // zob[(id*NN + cell)*32 + k]
unordered_set<ull> visited;                    // 過去に現れた局面

ull stateHash() {
    ull h = 0;
    for (int id = 0; id < S; id++) if (slimes[id].remain) {
        const Slime& s = slimes[id];
        h ^= zob[((size_t)id * NN + s.y * N + s.x) * 32 + s.k];
    }
    return h;
}

// 指すと過去の局面に戻ってしまう手を取り除く
void filterVisited(vector<Hand>& hs) {
    vector<Hand> keep;
    for (auto& h : hs) {
        UndoRec u = doMove(h);
        bool seen = visited.count(stateHash()) > 0;
        undoMove(u);
        if (!seen) keep.push_back(h);
    }
    hs.swap(keep);
}

// ===================== 評価 =====================
// 1手の点数（大きいほど良い）。元のコードの評価関数と同じ内容
ll handScore(const Hand& h) {
    int sc = h.y * N + h.x, tc = destCell(h);
    const auto& v = cells[sc].st; const auto& w = cells[tc].st;
    int jumpNum = (int)v.size() - h.k;                  // 飛ぶ匹数
    int topC = slimes[v.back()].c;                      // 一番上（行き先で相手の上に乗る）
    int botC = slimes[v[h.k]].c;                        // 一緒に動く一番下
    int underC = h.k > 0 ? slimes[v[h.k - 1]].c : -1;   // 残るスライムの一番上
    ll score = 0;

    // 行き先の一番上と同じ色でつながる
    if (!w.empty() && slimes[w.back()].c == topC) score += 100;

    // 同じ色を引き離す
    if (botC == underC) {
        if      (jumpNum <= 3) score -= 150;
        else if (jumpNum <= 5) score -= 120;
        else if (jumpNum <= 6) score -= 70;
        else if (jumpNum <= 7) score -= 10;
        else                   score += 100;
    }

    // 動くスライム全員について、巣に近づいた距離
    for (int i = h.k; i < (int)v.size(); i++) {
        int hc = holeCell[slimes[v[i]].c];
        score += (ll)(dist(sc, hc) - dist(tc, hc)) * 10;
    }
    return score;
}

// 先読み付きの点数： value(h) = handScore(h) + max(次の手の value) / 10
vector<vector<Hand>> handBuf(16);
vector<vector<pair<ll, int>>> orderBuf(16);

ll handValue(const Hand& h, int depth) {
    ll s = handScore(h);
    if (depth <= 1) return s;

    UndoRec u = doMove(h);
    auto& nx = handBuf[depth];
    makeHand(nx, false, false, false);
    if (nx.empty()) {                       // 次の手が無い
        if (remainCnt > 0) s -= STUCK_PENALTY;   // 残っているのに動けない = 詰み
        undoMove(u);
        return s;
    }
    ll mx = LLONG_MIN;
    if (depth == 2) {
        for (auto& h2 : nx) mx = max(mx, handScore(h2) / 10);
    } else {
        // handScore の上位 BEAM_M 手だけを深く読む
        auto& ord = orderBuf[depth];
        ord.clear();
        for (int i = 0; i < (int)nx.size(); i++) ord.push_back({-handScore(nx[i]), i});
        int take = min(BEAM_M, (int)ord.size());
        partial_sort(ord.begin(), ord.begin() + take, ord.end());
        for (int t = 0; t < take; t++) {
            Hand h2 = nx[ord[t].second];    // 再帰中に nx が書き換わらないようコピー
            mx = max(mx, handValue(h2, depth - 1) / 10);
        }
    }
    undoMove(u);
    return s + mx;
}

int chooseHand(const vector<Hand>& hands, int depth) {
    ll best = LLONG_MIN; int choice = 0;
    for (int i = 0; i < (int)hands.size(); i++) {
        ll v = handValue(hands[i], depth);
        if (v > best) { best = v; choice = i; }
    }
    return choice;
}

// ===================== 初期化 =====================
void buildDist() {
    D.assign((size_t)NN * NN, -1);
    vector<int> q(NN);
    for (int src = 0; src < NN; src++) {
        int* row = &D[(size_t)src * NN];
        int qh = 0, qt = 0;
        q[qt++] = src; row[src] = 0;
        while (qh < qt) {
            int cur = q[qh++], cy = cur / N, cx = cur % N;
            for (int i = 0; i < 4; i++) {
                int ny = cy + dirY[i], nx = cx + dirX[i];
                if (!inField(ny, nx)) continue;
                int nc = ny * N + nx;
                if (row[nc] < 0) { row[nc] = row[cur] + 1; q[qt++] = nc; }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    auto startTime = chrono::steady_clock::now();
    auto elapsedMs = [&]() {
        return chrono::duration<double, milli>(chrono::steady_clock::now() - startTime).count();
    };

    // ---- 入力 ----
    cin >> N >> K;
    NN = N * N;
    cells.assign(NN, Cell());
    holeCell.assign(K, 0);
    for (int y = 0; y < N; y++) {
        string s; cin >> s;
        for (int x = 0; x < N; x++) {
            char ch = s[x];
            Cell& C = cells[y * N + x];
            C.st.reserve(32);
            if (ch == '#') continue;
            C.ground = true;
            if ('A' <= ch && ch <= 'Z') {
                C.hole = ch - 'A';
                holeCell[C.hole] = y * N + x;
            } else if ('a' <= ch && ch <= 'z') {
                C.st.push_back((int)slimes.size());
                slimes.push_back({y, x, ch - 'a', 0, true});
            }
        }
    }
    S = (int)slimes.size();
    remainCnt = S;
    buildDist();

    // 局面ハッシュ用の乱数表
    zob.resize((size_t)S * NN * 32);
    ull r = 88172645463325252ULL;
    for (auto& z : zob) { r ^= r << 13; r ^= r >> 7; r ^= r << 17; z = r; }
    visited.insert(stateHash());

    // ---- メインループ ----
    vector<Hand> hands;
    int turn = 0;
    while (remainCnt > 0 && turn < MAX_TURN) {
        // 1. 各色で一番遠いスライムの手（指した手は除く）
        makeHand(hands, true, true, false);
        // 2. 全スライムの手（指した手は除く）
        if (hands.empty()) makeHand(hands, false, true, false);
        // 3. 指した手も含める。ただし過去の局面に戻る手は除く
        if (hands.empty()) { makeHand(hands, false, false, false); filterVisited(hands); }
        // 4. 詰み脱出：遠ざかる手も許可
        if (hands.empty()) makeHand(hands, false, true, true);
        if (hands.empty()) makeHand(hands, false, false, true);
        if (hands.empty()) break;

        int depth = (elapsedMs() < TIME_LIMIT_MS * 0.8) ? DEPTH : 1;
        const Hand h = hands[chooseHand(hands, depth)];

        cout << h.y << ' ' << h.x << ' ' << h.k << ' ' << dirCh[h.d] << ' ' << h.j << '\n';
        played.insert(handHash(h));
        doMove(h);
        visited.insert(stateHash());
        turn++;
    }
    cout.flush();
    // デバッグ情報は標準エラーへ（ジャッジの判定対象外）
    cerr << "turns=" << turn << " remain=" << remainCnt << " time=" << elapsedMs() << "ms\n";
    return 0;
}