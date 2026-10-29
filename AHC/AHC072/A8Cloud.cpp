#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

// ===== 盤面状態（1次元化・コピーしない） =====
int N, K, NN, S;
vector<char> ground;          // ground[y*N+x]
vector<int> holeC;            // そのマスの巣の色（なければ -1）
vector<int> holeCell;         // 色 c の巣のマス番号
vector<vector<int>> st;       // 各マスのスライムID スタック（back が一番上）
vector<int> D;                // D[a*NN + b] : マス a からマス b への最短距離（到達不能は -1）

struct Slime { int y, x, c, k; bool remain; int canMoveNum; };
vector<Slime> sl;

const int dirX[4] = {-1, 0, 1, 0}, dirY[4] = {0, -1, 0, 1};
const char dirCh[4] = {'L', 'U', 'R', 'D'};

inline int dist(int a, int b) { return D[a * NN + b]; }
inline int cnt(int c) { return (int)st[c].size(); }
inline bool inField(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N && ground[y * N + x];
}

// ===== 差分ログ（盤面コピーの代わりに undo で元に戻す） =====
struct Log { int type, cell, id; Slime old; }; // 0:push 1:pop 2:slime変更
vector<Log> logs;

inline void pushC(int c, int id) { st[c].push_back(id); logs.push_back({0, c, id, {}}); }
inline int popC(int c) { int id = st[c].back(); st[c].pop_back(); logs.push_back({1, c, id, {}}); return id; }
inline void saveSlime(int id) { logs.push_back({2, -1, id, sl[id]}); }

void undoAll() {
    for (int i = (int)logs.size() - 1; i >= 0; i--) {
        const Log& l = logs[i];
        if (l.type == 0) st[l.cell].pop_back();
        else if (l.type == 1) st[l.cell].push_back(l.id);
        else sl[l.id] = l.old;
    }
    logs.clear();
}

inline void removeAtHole(int c) {
    int h = holeC[c];
    if (h < 0) return;
    while (!st[c].empty()) {
        int id = st[c].back();
        if (sl[id].c != h) break;
        popC(c);
        saveSlime(id);
        sl[id].remain = false;
    }
}

struct Hand { int y, x, k, d, dis, slimeId, jumpSlime; };

void doMove(const Hand& h) {
    int ny = h.y + dirY[h.d] * h.dis, nx = h.x + dirX[h.d] * h.dis;
    int c = h.y * N + h.x, nc = ny * N + nx;
    while (cnt(c) > h.k) {
        int id = popC(c);
        saveSlime(id);
        sl[id].y = ny; sl[id].x = nx;
        sl[id].k = cnt(nc);
        pushC(nc, id);
    }
    removeAtHole(nc);
    removeAtHole(c);
}

// doMove 適用後の状態で評価（元の evaluateScore と同じ計算）
int evaluateScore(const Hand& hand) {
    int score = 0;
    const int beforeC = hand.y * N + hand.x;
    const int nowY = hand.y + dirY[hand.d] * hand.dis;
    const int nowX = hand.x + dirX[hand.d] * hand.dis;
    const int nowC = nowY * N + nowX;
    const vector<int>& stk = st[nowC];
    const int sz = (int)stk.size();

    int beginIdx = (int)(find(stk.begin(), stk.end(), hand.slimeId) - stk.begin());
    int jumpSLime = hand.jumpSlime;
    score -= sz * 20;
    int beforeSlimeC = -1;
    for (; beginIdx < sz; beginIdx++) {
        jumpSLime--;
        const Slime& s = sl[stk[beginIdx]];
        if (s.c == beforeSlimeC) score -= 5;
        beforeSlimeC = s.c;
        score += s.canMoveNum;
        const int hc = holeCell[s.c];
        const int a = dist(nowC, hc), b = dist(beforeC, hc);
        score += 100 * a * a;
        score -= 100 * b * b;

        const int sc = s.y * N + s.x;
        const int dsh = dist(sc, hc);
        const int base = cnt(sc) - s.k;
        for (int i = 0; i < 4; i++) {
            for (int j = 1; j <= s.k + 1; j++) {
                int ny = s.y + dirY[i] * j, nx = s.x + dirX[i] * j;
                if (!inField(ny, nx)) break;
                int nc = ny * N + nx;
                if (cnt(nc) + base <= 8 && dsh > dist(nc, hc)) score -= 1;
            }
        }
    }
    const int e = dist(nowC, beforeC);
    score -= 100 * jumpSLime * e * jumpSLime * e;
    score -= jumpSLime * 5;
    return score;
}

// 元コード同様、canMoveNum を実盤面のスライムに書き込む
void makeHand(vector<Hand>& hands) {
    hands.clear();
    for (int id = 0; id < S; id++) {
        Slime& s = sl[id];
        if (!s.remain) continue;
        s.canMoveNum = 0;
        const int c = s.y * N + s.x;
        const int hc = holeCell[s.c];
        const int dch = dist(c, hc);
        const int base = cnt(c) - s.k;
        const int top = st[c].back();
        for (int d = 0; d < 4; d++) {
            for (int j = 1; j <= s.k + 1; j++) {
                int ny = s.y + dirY[d] * j, nx = s.x + dirX[d] * j;
                if (!inField(ny, nx)) break;
                int nc = ny * N + nx;
                if (cnt(nc) + base <= 8 && dch > dist(nc, hc)) {
                    hands.push_back({s.y, s.x, s.k, d, j, top, base});
                    s.canMoveNum++;
                }
            }
        }
    }
}

void makePlaceToPlace() {
    D.assign((size_t)NN * NN, -1);
    vector<int> q(NN);
    for (int src = 0; src < NN; src++) {
        int* row = &D[(size_t)src * NN];
        int qh = 0, qt = 0;
        q[qt++] = src; row[src] = 0;
        while (qh < qt) {
            int cur = q[qh++];
            int cy = cur / N, cx = cur % N;
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

    cin >> N >> K;
    NN = N * N;
    ground.assign(NN, 0);
    holeC.assign(NN, -1);
    holeCell.assign(K, 0);
    st.assign(NN, {});
    for (int y = 0; y < N; y++) {
        string s; cin >> s;
        for (int x = 0; x < N; x++) {
            char ch = s[x];
            int cell = y * N + x;
            if (ch == '#') continue;
            ground[cell] = 1;
            if ('A' <= ch && ch <= 'Z') {
                holeC[cell] = ch - 'A';
                holeCell[ch - 'A'] = cell;
            } else if ('a' <= ch && ch <= 'z') {
                st[cell].push_back((int)sl.size());
                sl.push_back({y, x, ch - 'a', 0, true, 0});
            }
        }
    }
    S = (int)sl.size();
    makePlaceToPlace();
    logs.reserve(1 << 12);

    vector<Hand> hands;
    while (true) {
        makeHand(hands);
        if (hands.empty()) break;
        int best = INT_MAX, choice = 0;
        for (int i = 0; i < (int)hands.size(); i++) {
            doMove(hands[i]);
            int score = evaluateScore(hands[i]);
            undoAll();
            if (score < best) { best = score; choice = i; }
        }
        const Hand& h = hands[choice];
        cout << h.y << ' ' << h.x << ' ' << h.k << ' ' << dirCh[h.d] << ' ' << h.dis << '\n';
        doMove(h);
        logs.clear();
    }
    return 0;
}