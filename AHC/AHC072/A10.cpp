#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <climits>

using namespace std;
using ll = long long;





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
                    // cout << "slime!" << endl;;
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

struct Output{
    int x;
    int y;
    int k; //残すスライム数
    char dir; //方向
    int dis; // 距離
    int dirNum;
    int jumpSlime;//飛んだスライム
    int jumpSlimeNum; //飛ぶスライムの量
    Output(int y_, int x_, int k_, char dir_, int dis_, int slimeId_, int jumpSlime_, int jumpSlimeNum_){
        x = x_;
        y = y_;
        k = k_;
        dir = dir_;
        dis = dis_;
        jumpSlime = jumpSlime_;
        jumpSlimeNum = jumpSlimeNum_;
        if(dir == 'L') dirNum = 0;
        if(dir == 'U') dirNum = 1;
        if(dir == 'R') dirNum = 2;
        if(dir == 'D') dirNum = 3;
    }

    void put(){
        cout << y << " " << x << " " << k << " " << dir << " " << dis << endl;
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

ll N, K;

vector<vector<vector<vector<int>>>> placetoPlace;
vector<vector<int>>placeWeight;
vector<Hole> vecHole;
vector<vector<Place>> field;

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

void move(Output, vector<vector<Place>>&, vector<Slime>&);
vector<Output> makeHand(vector<vector<Place>>&, vector<Slime>&);



int evaluateScore(Output hand, vector<vector<Place>>& field, vector<Slime>& slimes){
    int score = 0;
    int nextY = hand.y + dirY[hand.dir] * hand.dis;
    int nextX = hand.x + dirX[hand.dir] * hand.dis;
    auto moveSlime = hand.jumpSlime;
    auto jumpSlime = slimes[hand.jumpSlime];
    auto topSlime = slimes[field[hand.y][hand.x].slimeId.back()];
    int underColor = -1;
    if(hand.k > 0){
        int underSlimeId = field[hand.y][hand.x].slimeId[hand.k - 1];
        underColor = slimes[underSlimeId].c;
    }
    
    // 次のマスのスライムと同じ色で繋がる。
    if(field[nextY][nextX].slimeNum > 0){
        if(topSlime.c == slimes[field[nextY][nextX].slimeId.back()].c){
            score += 100000;
        }
    }
    // 同じ色が離れる場合下げる
    if(jumpSlime.c == underColor){
        score -= 10000;
    }
    score += placeWeight[nextY][nextX] * 10;

    //距離が遠い方が+
    int holeY = vecHole[jumpSlime.c].y;
    int holeX = vecHole[jumpSlime.c].x;
    score += placetoPlace[hand.y][hand.x][holeY][holeX] * placetoPlace[hand.y][hand.x][holeY][holeX];
    score -= placetoPlace[nextY][nextX][holeY][holeX] * placetoPlace[nextY][nextX][holeY][holeX];
    score += hand.dis * 10;
    score += field[nextY][nextX].slimeNum * 10;
    return score;
    
}


void move(Output choice, vector<vector<Place>> &movingField, vector<Slime> &slimes){

    int y = choice.y;
    int x = choice.x;
    int dist = choice.dis;
    int nextY = y + dirY[choice.dirNum] * dist;
    int nextX = x + dirX[choice.dirNum] * dist;

    while(movingField[y][x].slimeNum > choice.k){ //移動操作

        int id = movingField[y][x].slimeId.back();

        slimes[id].y = nextY;
        slimes[id].x = nextX;
        
        slimes[id].k = movingField[nextY][nextX].slimeNum;


        movingField[y][x].slimeNum --;
        movingField[nextY][nextX].slimeNum ++;

        movingField[nextY][nextX].slimeId.push_back(movingField[y][x].slimeId.back());
        movingField[y][x].slimeId.pop_back();
    }

    while(true){// 巣に帰る時
        if(movingField[nextY][nextX].hole == -1) break;
        if(movingField[nextY][nextX].slimeId.empty()) break;

        int id = movingField[nextY][nextX].slimeId.back();

        if(movingField[nextY][nextX].hole != slimes[id].c) break;

        movingField[nextY][nextX].slimeNum--;
        movingField[nextY][nextX].slimeId.pop_back();
        slimes[id].remain = false;
    }
    while(true){
        if(movingField[y][x].hole == -1) break;
        if(movingField[y][x].slimeId.empty()) break;

        int id = movingField[y][x].slimeId.back();

        if(movingField[y][x].hole != slimes[id].c) break;
        movingField[y][x].slimeNum --;
        movingField[y][x].slimeId.pop_back();
        slimes[id].remain = false;
    }

    return;
}



vector<Output> makeHand(vector<vector<Place>> &handField, vector<Slime> &slimes){
    vector<Output> allHand;
    for(Slime& sl: slimes){
        if(!sl.remain){
            continue;
        }
        if(!sl.remain) continue;

        auto &p = field[sl.y][sl.x];
        sl.canMoveNum = 0;
        for(int i = 0; i < 4; i ++){ //方向
            for(int j = 1; j <= sl.k + 1; j ++){//jump距離
                // cout << i << j << endl;
                int nextY = sl.y + dirY[i] * j;
                int nextX = sl.x + dirX[i] * j;
                int holeY = vecHole[sl.c].y;
                int holeX = vecHole[sl.c].x;
                if(inField(nextY, nextX)){

                    if(field[nextY][nextX].slimeNum + field[sl.y][sl.x].slimeNum - sl.k <= 8 && placetoPlace[sl.y][sl.x][holeY][holeX] > placetoPlace[nextY][nextX][holeY][holeX]){
                        
                        char dir = getDirection(sl.y, sl.x, nextY, nextX);
                        allHand.push_back(Output(sl.y, sl.x, sl.k, dir, j, field[sl.y][sl.x].slimeId.back(), sl.id, field[sl.y][sl.x].slimeNum - sl.k));

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
    vector<Slime> slimes;
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

    placetoPlace = makePlaceToPlace();
    placeWeight = makePlaceWeight();

    //初期化処理完了

    int cnt = 0;
    while(true){
        cnt ++;
        auto allhand = makeHand(field, slimes);
        
        int max = INT_MIN;
        if(allhand.size() == 0){
            break;
        }
        int choice = 0;
        
        for(int i = 0; i < allhand.size(); i ++){
            Output hand = allhand[i];
            int score = evaluateScore(hand, field, slimes);
            if(score > max){
                max = score;
                choice = i;
            }
            // hand.put();
            // cout << "score = " << score << endl;

        }       
        allhand[choice].put();
        // cout << choice << endl;
        move(allhand[choice], field, slimes);
        if(cnt > 700){
            break;
        }

    }
    for(int y = 0; y < N; y ++){
        for(int x = 0; x < N; x ++){
            cout << placeWeight[y][x] << " ";
        }
        cout << endl;
    }
    cout << cnt << endl;


    

}




