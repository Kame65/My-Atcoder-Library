#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <climits>
#include <unordered_map>

using namespace std;
using ll = long long;


ll N, K;
int S;


// field[y][x]

struct Place{
    public:
    static int placeCnt;
    bool ground;
    int slimeNum;
    int hole;
    vector<int> slimeId;
    Place(){
        ground = false;
        slimeNum = 0;
        hole = -1;
    }
    Place(char c){
        if(c == '#'){
            slimeNum = 0;
            ground = false;
            hole = -1;
        }else{
            ground = true;
            if(0 <= c - 'A' && c - 'A' <= 'Z' - 'A'){
                hole = c - 'A';
                slimeNum = 0;
            }else{
                hole = -1;
                if(0 <= c - 'a' && c - 'a' <= 'z' - 'a'){
                    slimeNum = 1;
                    slimeId.push_back(placeCnt);
                    placeCnt ++;
                }else{
                    slimeNum = 0;
                }
            }
            
        }
    }
};
int Place::placeCnt = 0;

struct UndoInfo{
    public: 
    int y0, x0;
    int y1, x1;
    vector<int>p0SlimeId;
    vector<int>p1SlimeId;
    UndoInfo(){}
    UndoInfo(int y0_, int x0_, int y1_, int x1_, vector<int>p0s_, vector<int>p1s_){
        y0 = y0_;
        x0 = x0_;
        y1 = y1_;
        x1 = x1_;
        p0SlimeId = p0s_;
        p1SlimeId = p1s_;
    }
};

struct Output{
    int x;
    int y;
    int k; //残すスライム数
    char dir; //方向
    int dis; // 距離
    int dirNum;
    int jumpSlime;//飛んだスライム
    int jumpSlimeNum; //飛ぶスライムの量
    UndoInfo unInfo;
    Output(int y_, int x_, int k_, char dir_, int dis_, int slimeId_, int jumpSlime_, int jumpSlimeNum_, UndoInfo unInfo_){
        x = x_;
        y = y_;
        k = k_;
        dir = dir_;
        dis = dis_;
        jumpSlime = jumpSlime_;
        jumpSlimeNum = jumpSlimeNum_;
        unInfo = unInfo_;
        if(dir == 'L') dirNum = 0;
        if(dir == 'U') dirNum = 1;
        if(dir == 'R') dirNum = 2;
        if(dir == 'D') dirNum = 3;
    }

    void put(){
        cout << y << " " << x << " " << k << " " << dir << " " << dis << endl;
    }
    ll hash(){
        return ((((y * N + x) * 9 + k) * 4 + dirNum) * S + jumpSlime);
    }
};

struct Slime{
    int y;
    int x;
    int c;
    int k;//下から何番目か 地面の場合0
    int id;
    bool remain;//fieldに残っているか
    int canMoveNum;

    Slime(int y_, int x_, int c_, int k_, int id_){
        y = y_;
        x = x_;
        c = c_;
        k = k_;
        id = id_;
        remain = true;
        canMoveNum = 0;
    }

    Slime(){
        y = -1;
        x = -1;
        c = -1;
        k = -1;
        id = -1;
        remain = false;
    }

};

struct Hole{
    public:
    int y;
    int x;
    Hole(){
        y = -1;
        x = -1;
    }
    Hole(int y_, int x_){
        y = y_;
        x = x_;
    };

};



vector<vector<vector<vector<int>>>> placetoPlace;
vector<vector<int>>placeWeight;
vector<Hole> vecHole;
vector<vector<Place>> field;
vector<Slime>slimes;
unordered_map<ll, bool> memo;
const int DEPTHLIMIT = 1;
bool RETREAT = false;
// 160000 * y + 8000 * x + 400 * k + 20 * disNum + l をhashとする。

Place NONE = Place('.');
int dirX[] = {-1, 0, 1, 0}, dirY[] = {0, -1, 0, 1};
pair<int, int> GOAL = make_pair(-2, -2);
pair<int, int> START = make_pair(-3, -3);


bool inField(int y, int x){
    if(0 <= x && x <= N - 1 && 0 <= y && y <= N - 1 && field[y][x].ground){
        return true;
    }
    return false;
}

char getDirection(int nowY, int nowX, int afterY, int afterX){
    if(afterY - nowY > 0){
        return 'D';
    }
    if(afterY - nowY < 0){
        return 'U';
    }
    if(afterX - nowX > 0){
        return 'R';
    }
    if(afterX - nowX < 0){
        return 'L';
    }
    return 'E';
}

int getDist(int nowY, int nowX, int afterY, int afterX){
    return abs(afterY - nowY) + abs(afterX - nowX);
}

int remainCount(){
    int r = 0;
    for(auto& s : slimes){
        r += s.remain;
    }  
    return r; 
}



void move(Output);
void undo(Output);
vector<Output> makeHand(bool, bool);



int evaluateScore(Output hand, int depth = 0){
    //評価値の基準
    //同じ色で行動できるか
    //ゴールに全てのスライムが近づく距離が大きいか
    int score = 0;
    int nextY = hand.y + dirY[hand.dirNum] * hand.dis;
    int nextX = hand.x + dirX[hand.dirNum] * hand.dis;
    auto jumpSlime = slimes[hand.jumpSlime];
    vector<Slime> allMoveSlime;
    for(int i = hand.k; i < hand.k + hand.jumpSlimeNum; i ++){
        allMoveSlime.push_back(slimes[field[hand.y][hand.x].slimeId[i]]);
    }
    auto topSlime = slimes[field[hand.y][hand.x].slimeId.back()];
    int underColor = -1;

    if(hand.k > 0){
        int underSlimeId = field[hand.y][hand.x].slimeId[hand.k - 1];
        underColor = slimes[underSlimeId].c;
    }
    
    // 次のマスのスライムと同じ色で繋がる。
    if(field[nextY][nextX].slimeNum > 0){
        if(topSlime.c == slimes[field[nextY][nextX].slimeId.back()].c){
            score += 100;
        }
    }
    // 同じ色が離れる場合下げる
    if(jumpSlime.c == underColor){
        if(hand.jumpSlimeNum <= 3){
            score -= 150;
        }else if(hand.jumpSlimeNum <= 4){
            score -= 120;
        }else if(hand.jumpSlimeNum <= 5){
            score -= 120;
        }else if(hand.jumpSlimeNum <= 6){
            score -= 70;
        }else if(hand.jumpSlimeNum <= 7){
            score -= 10;
        }else{
            score += 100;
        }
    }

    //距離が遠い方が+

    for(auto sl: allMoveSlime){
        int holeY = vecHole[sl.c].y;
        int holeX = vecHole[sl.c].x;
        int oneDistance = placetoPlace[hand.y][hand.x][holeY][holeX] - placetoPlace[nextY][nextX][holeY][holeX];
        score += oneDistance * 10;
    }

    if(depth == DEPTHLIMIT){
        return score;
    }
    
    // cout << "begin Move" << endl;

    move(hand);    
    int max = INT_MIN;
    auto nextHands = makeHand(false, false);
    if(nextHands.size() == 0){
        bool stuck = remainCount() > 0;   // undo の前に判定
        undo(hand);
        return stuck ? score - 100000 : score;
    }
    int choice = 0;

    for(int i = 0; i < nextHands.size(); i ++){
        Output nextHand = nextHands[i];
        int score = evaluateScore(nextHand, depth + 1) / 10;
        if(score > max){
            max = score;
            choice = i;
        }

    }       
    undo(hand);
    score += max;
    
    return score;
    
}


void move(Output choice){

    int y = choice.y;
    int x = choice.x;
    int dist = choice.dis;
    int nextY = y + dirY[choice.dirNum] * dist;
    int nextX = x + dirX[choice.dirNum] * dist;

    while(field[y][x].slimeNum > choice.k){ //移動操作

        int id = field[y][x].slimeId.back();

        slimes[id].y = nextY;
        slimes[id].x = nextX;
        
        slimes[id].k = field[nextY][nextX].slimeNum;


        field[y][x].slimeNum --;
        field[nextY][nextX].slimeNum ++;

        field[nextY][nextX].slimeId.push_back(field[y][x].slimeId.back());
        field[y][x].slimeId.pop_back();
    }

    while(true){// 巣に帰る時
        if(field[nextY][nextX].hole == -1) break;
        if(field[nextY][nextX].slimeId.empty()) break;

        int id = field[nextY][nextX].slimeId.back();

        if(field[nextY][nextX].hole != slimes[id].c) break;

        field[nextY][nextX].slimeNum--;
        field[nextY][nextX].slimeId.pop_back();
        slimes[id].remain = false;
    }
    while(true){
        if(field[y][x].hole == -1) break;
        if(field[y][x].slimeId.empty()) break;

        int id = field[y][x].slimeId.back();

        if(field[y][x].hole != slimes[id].c) break;
        field[y][x].slimeNum --;
        field[y][x].slimeId.pop_back();
        slimes[id].remain = false;
    }

    return;
}

void undo(Output choice){
    auto unI = choice.unInfo;
    field[unI.y0][unI.x0].slimeNum = unI.p0SlimeId.size();
    field[unI.y0][unI.x0].slimeId = unI.p0SlimeId;
    field[unI.y1][unI.x1].slimeNum = unI.p1SlimeId.size();
    field[unI.y1][unI.x1].slimeId = unI.p1SlimeId;
    int idx = 0;
    for(int id: unI.p0SlimeId){
        slimes[id].remain = true;
        slimes[id].y = unI.y0;
        slimes[id].x = unI.x0;
        slimes[id].k = idx;
        idx ++;
    }
    idx = 0;
    for(int id: unI.p1SlimeId){
        slimes[id].remain = true;
        slimes[id].y = unI.y1;
        slimes[id].x = unI.x1;
        slimes[id].k = idx;
        idx ++;
    }
    memo[choice.hash()] = false;

}

vector<Output> makeHand(bool maxDistance, bool memoBlock){
    vector<Output> allHand;
    vector<int>vecDisMax(K, 0);
    for(Slime&sl: slimes){
        if(!sl.remain){
            continue;
        }
        int distance = placetoPlace[sl.y][sl.x][vecHole[sl.c].y][vecHole[sl.c].x];
        if(vecDisMax[sl.c] < distance){
            vecDisMax[sl.c] = distance;
        }
        
        
    }
    for(Slime& sl: slimes){
        if(!sl.remain){
            continue;
        }
        if(maxDistance && placetoPlace[sl.y][sl.x][vecHole[sl.c].y][vecHole[sl.c].x] != vecDisMax[sl.c]){
            continue;
        }

        auto &p = field[sl.y][sl.x];
        sl.canMoveNum = 0;
        for(int i = 0; i < 4; i ++){ //方向
            for(int j = 1; j <= sl.k + 1; j ++){//jump距離
                int nextY = sl.y + dirY[i] * j;
                int nextX = sl.x + dirX[i] * j;
                int holeY = vecHole[sl.c].y;
                int holeX = vecHole[sl.c].x;
                if(inField(nextY, nextX)){
                    
                    if(field[nextY][nextX].slimeNum + field[sl.y][sl.x].slimeNum - sl.k <= 8
                    && (RETREAT || placetoPlace[sl.y][sl.x][holeY][holeX] > placetoPlace[nextY][nextX][holeY][holeX])){
                        
                        char dir = getDirection(sl.y, sl.x, nextY, nextX);
                        UndoInfo unI = UndoInfo(sl.y, sl.x, nextY, nextX, field[sl.y][sl.x].slimeId, field[nextY][nextX].slimeId);
                        auto out = Output(sl.y, sl.x, sl.k, dir, j, field[sl.y][sl.x].slimeId.back(), sl.id, field[sl.y][sl.x].slimeNum - sl.k, unI);
                        if(memoBlock && memo[out.hash()]){
                            continue;
                        }
                        allHand.push_back(out);

                        sl.canMoveNum ++;
                    }

                }else{
                    break;
                }
            }
        }
    }

    return allHand;

}

vector<vector<vector<vector<int>>>> makePlaceToPlace(){
    vector<vector<vector<vector<int>>>>result(N, vector<vector<vector<int>>>(N, vector<vector<int>>(N, vector<int>(N, -1))));
    for(int y0 = 0; y0 < N; y0 ++){
        for(int x0 = 0; x0 < N; x0 ++){
            queue<vector<int>> q;
            q.push({y0, x0, 0});
            vector<vector<int>>&place = result[y0][x0];
            place[y0][x0] = 0;
            while(q.size() > 0){
                auto nowPlace = q.front();
                q.pop();
                int pY = nowPlace[0];
                int pX = nowPlace[1];
                int dist = nowPlace[2];
                int nextY, nextX;
                for(int i = 0; i < 4; i ++){
                    nextY = pY + dirY[i];
                    nextX = pX + dirX[i];
                    
                    if(inField(nextY, nextX) && place[nextY][nextX] < 0){
                        q.push({nextY, nextX, dist + 1});
                        place[nextY][nextX] = dist + 1;
                    }
                }

            }

        }
    }
    return result;
}

vector<vector<int>> makePlaceWeight(){
    vector<vector<int>>result(N, vector<int>(N, 0));
    int sum = 0;
    for(int y0 = 0; y0 < N; y0 ++){
        for(int x0 = 0; x0 < N; x0 ++){
            for(int i = 0; i < 4; i ++){
                for(int j = 1; j < 3; j ++){
                    int nextY = y0 + dirY[i] * j;
                    int nextX = x0 + dirX[i] * j;
                    if(inField(nextY, nextX)){
                        result[y0][x0] ++;
                        sum ++;
                    }else{
                        break;
                    }
                }
            }
        }
    }
    int ave = sum / N / N;
    for(int y = 0; y < N; y ++){
        for(int x = 0; x < N; x ++){
            result[y][x] -= ave;
            result[y][x] = result[y][x] * result[y][x];
        }
    }
    return result;
}

int main(){
    cin >> N >> K;
    field = vector<vector<Place>>(N, vector<Place>(N));
    vecHole = vector<Hole>(K);
    int slimeCnt = 0;

    for(ll y = 0; y < N; y ++){
        string strC;
        cin >> strC;
        for(ll x = 0; x < N; x ++){
            field[y][x] = Place(strC[x]);
            if(field[y][x].slimeNum > 0){
                slimes.push_back(Slime(y, x, (strC[x] - 'a'), 0, slimeCnt));
                slimeCnt ++;
            }
            if(field[y][x].hole >= 0){
                vecHole[field[y][x].hole] = Hole(y, x);
            }
        }
    }
    S = slimes.size();

    placetoPlace = makePlaceToPlace();
    placeWeight = makePlaceWeight();

    //初期化処理完了

    int cnt = 0;
    while(true){
        
        auto allhand = makeHand(true, true);
        if(allhand.size() == 0) allhand = makeHand(false, true);
        if(allhand.size() == 0) allhand = makeHand(false, false);
        if(allhand.size() == 0){
            if(remainCount() == 0) break;          // 全部帰ったら終了
            RETREAT = true;
            allhand = makeHand(false, true);
            if(allhand.size() == 0) allhand = makeHand(false, false);
            RETREAT = false;
            if(allhand.size() == 0) break;
        }
        int max = INT_MAX;
        int choice = 0;
        
        for(int i = 0; i < allhand.size(); i ++){
            Output hand = allhand[i];
            // cout << "begin evaluate: " << endl;
            // for(int y = 0; y < N; y ++){
            //     for(int x = 0; x < N; x ++){
            //         cout << field[y][x].slimeNum << " ";
            //     }
            //     cout << endl;
            // }
            int score = evaluateScore(hand);
            // cout << "end evaluate: " << endl;
            // for(int y = 0; y < N; y ++){
            //     for(int x = 0; x < N; x ++){
            //         cout << field[y][x].slimeNum << " ";
            //     }
            //     cout << endl;
            // }
            if(score > max){
                max = score;
                choice = i;
            }

        }       
        cnt ++;
        allhand[choice].put();

        move(allhand[choice]);
        memo[allhand[choice].hash()] = true;


    }
    // for(auto sl: slimes){
    //     if(sl.remain){
    //         cout << "remain" << endl;
    //         break;
    //     }
    // }
    // cout << "score = " << cnt << endl;



    

}




