#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;
using ll = long long;





// field[y][x]

struct Place{
    public:
    static int cnt;
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
                    slimeId.push_back(cnt);
                    cnt ++;
                }else{
                    slimeNum = 0;
                }
            }
            
        }
    }
};
int Place::cnt = 0;

struct Output{
    int x;
    int y;
    int k; //残すスライム数
    char dir; //方向
    int dis; // 距離
    int dirNum;
    Output(int y_, int x_, int k_, char dir_, int dis_){
        x = x_;
        y = y_;
        k = k_;
        dir = dir_;
        dis = dis_;
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

    Slime(int y_, int x_, int c_, int k_, int id_){
        y = y_;
        x = x_;
        c = c_;
        k = k_;
        id = id_;
        remain = true;
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
    Hole(){}
    Hole(int y_, int x_){
        y = y_;
        x = x_;
    };

};

ll N, K;

vector<vector<vector<vector<int>>>> placetoPlace;
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

// i_0, j_0, k_0, d_0, l_0;
vector<Output> makeRouteBFS(int id, vector<vector<Place>>& bfsField, vector<Slime>& bfsSlimes){//ここにいるスライムにのみ指示で巣に返す, heightはスライム一匹の時1
    // cout << "in make BFS" << endl;
    Slime sl = bfsSlimes[id];
    
    int beginY = sl.y;
    int beginX = sl.x;
    int color = bfsSlimes[id].c;
    int height = bfsSlimes[id].k;
    // cout << "begin: " << beginY << " " << beginX << endl;
    // cout << "info: " << beginY << " " << beginX << " " << color << " " << height  << endl;
    // for(int y = 0; y < N; y ++){
    //     for(int x = 0; x < N; x ++){
    //         cout << bfsField[y][x].slimeNum << " ";
    //     }
    //     cout << endl;
    // }
    vector<Output> result;
    vector<vector<pair<int, int>>> already(N, vector<pair<int, int>>(N, make_pair(-1, -1)));// 0: LEFT, 1: UP
    queue<pair<int, int>> searchQ;
    int nowY = beginY;
    int nowX = beginX;
    pair<int, int> nowPlace = make_pair(nowY, nowX);
    searchQ.push(nowPlace);
    already[nowY][nowX] = START;
    int cnt = 0;
    // cout << "OK !!" << endl;
    while(searchQ.size() > 0){
        // cout << "cnt = " << cnt << endl;
        // cnt ++;
        
        nowPlace = searchQ.front();
        searchQ.pop();
        nowY = nowPlace.first;
        nowX = nowPlace.second;
        // cout << "search: " << endl;
        // cout << nowY << " " << nowX << endl;
        if(bfsField[nowY][nowX].hole == color){
            // goal到着 -> 経路復元
            // cout << "Goal" << endl;

            while(true){
                // cout << nowY << " " << nowX << endl;
                int afterY = nowY;
                int afterX = nowX;
                nowPlace = already[nowY][nowX];
                nowY = nowPlace.first;
                nowX = nowPlace.second;
                // cout << "2: " << nowY << nowX << endl;
                if(nowX == -3){//START
                    // cout << "Fin" << endl;
                    // char dir = getDirection(beginY, beginX, afterY, afterX);
                    // int dist = getDist(beginY, beginX, afterY, afterX);
                    // int jump = bfsField[beginY][beginX].slimeNum;
                    // result.push_back(Output(beginY, beginX, jump, dir, dist));


                    reverse(result.begin(), result.end());
                    return result;
                }
                char dir = getDirection(nowY, nowX, afterY, afterX);
                int dist = getDist(nowY, nowX, afterY, afterX);
                int remain = bfsField[nowY][nowX].slimeNum;//残っているスライムの数
                if(nowX == beginX && nowY == beginY){
                    // cout << "What" << endl;
                    remain = height;
                    // Output(nowPlace.first, nowPlace.second, remain, dir, dist).put();
                    move(Output(nowPlace.first, nowPlace.second, remain, dir, dist), bfsField, bfsSlimes);
                    // cout << "move is OK" << endl;
                    // cout << "OK" << endl;
                    if(bfsField[afterY][afterX].hole != color){// hole==colorの場合はmove()でスライムが消されるため必要なし
                        // cout << "erase: " << afterY << " " << afterX << endl;
                        bfsField[afterY][afterX].slimeNum --;
                        bfsField[afterY][afterX].slimeId.pop_back();
                    }
                    
                }
                result.push_back(Output(nowPlace.first, nowPlace.second, remain, dir, dist));
                // cout << "add: " << nowPlace.first << " " << nowPlace.second << endl;

            }
        }

        int jumpPower = bfsField[nowY][nowX].slimeNum + 1; //jumpできる距離
        if(nowY == beginY && nowX == beginX){
            jumpPower = height + 1;
        }
        // cout << "jP: " << jumpPower << endl;
        for(int i = 0; i < 4; i ++){
            for(int j = 1; j <= jumpPower; j ++){
                int nextY = nowY + dirY[i] * j;
                int nextX = nowX + dirX[i] * j;
                if(inField(nextY, nextX)){ 
                    if(already[nextY][nextX].first == -1){//壁がないかつ未探索
                    searchQ.push(make_pair(nextY, nextX));
                    already[nextY][nextX] = make_pair(nowY, nowX);
                    }
                }else{
                    break;
                }
            }
            
        }
        
    }
    return vector<Output>();
    
}


int evaluateScore(vector<vector<Place>>& field, vector<Slime>& slimes){
    int score = 0;
    
    for(Slime sl: slimes){
        // cout << sl.y << sl.x << sl.remain << endl;
        if(sl.remain){// スライムがいる
            int color = sl.c;

            // cout << "remain" << endl;
            score += 10 * placetoPlace[sl.y][sl.x][vecHole[color].y][vecHole[color].x];
            // cout << "distance: " << placetoPlace[sl.y][sl.x][vecHole[color].y][vecHole[color].x] << endl;
            // for(Output ot: result){
            //     ot.put();
            // }
        }
        
        // cout << sl.id << endl;
        // result += makeRouteBFS(sl.y, sl.x, sl.c, field).size();
    }
    // cout << slimes.size() << endl;
    // cout << "distanceScore" << score << endl;
    // score -= makeHand(field, slimes).size();
    return score;
}


void move(Output choice, vector<vector<Place>> &movingField, vector<Slime> &slimes){
// cout << "in Move" << endl;
    int y = choice.y;
    int x = choice.x;
    int dist = choice.dis;
    int nextY = y + dirY[choice.dirNum] * dist;
    int nextX = x + dirX[choice.dirNum] * dist;
    // choice.put();
    // cout << choice.dirNum << endl;
    while(movingField[y][x].slimeNum > choice.k){ //移動操作
        // cout << "begin moving" << endl;
        int id = movingField[y][x].slimeId.back();
        // cout << "id: " << id << endl;
        // cout << nextY << " " << nextX << " " << slimes[id].y << " " << slimes[id].x << endl;
        slimes[id].y = nextY;
        slimes[id].x = nextX;
        
        slimes[id].k = movingField[nextY][nextX].slimeNum;
        // cout << "chage Slimes info" << endl;

        movingField[y][x].slimeNum --;
        movingField[nextY][nextX].slimeNum ++;
        // cout << "increase: " << movingField[nextY][nextX].slimeNum << " " << nextY << " " << nextX << endl;
        movingField[nextY][nextX].slimeId.push_back(movingField[y][x].slimeId.back());
        movingField[y][x].slimeId.pop_back();
    }
    // cout << "res: " << movingField[0][11].slimeNum << endl;
    // cout << "begin hole precess" << endl;
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
    // for(int y = 0; y < N; y ++){
    //     for(int x = 0; x < N; x ++){
    //         // cout << y << "," << x << " ";
    //         cout << movingField[y][x].slimeNum << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "res: " << movingField[0][11].slimeNum << endl;
    return;
}



pair<vector<vector<Place>>, vector<Slime>> moveCopy(Output choice, vector<vector<Place>> movingField, vector<Slime> slimes){
    // cout << "in Move" << endl;
    int y = choice.y;
    int x = choice.x;
    int dist = choice.dis;
    int nextY = y + dirY[choice.dirNum] * dist;
    int nextX = x + dirX[choice.dirNum] * dist;
    // choice.put();
    // cout << choice.dirNum << endl;
    while(movingField[y][x].slimeNum > choice.k){ //移動操作
        // cout << "begin moving" << endl;
        int id = movingField[y][x].slimeId.back();
        // cout << "id: " << id << endl;
        // cout << nextY << " " << nextX << " " << slimes[id].y << " " << slimes[id].x << endl;
        slimes[id].y = nextY;
        slimes[id].x = nextX;
        
        slimes[id].k = movingField[nextY][nextX].slimeNum;
        // cout << "chage Slimes info" << endl;

        movingField[y][x].slimeNum --;
        movingField[nextY][nextX].slimeNum ++;
        // cout << "increase: " << movingField[nextY][nextX].slimeNum << " " << nextY << " " << nextX << endl;
        movingField[nextY][nextX].slimeId.push_back(movingField[y][x].slimeId.back());
        movingField[y][x].slimeId.pop_back();
    }
    // cout << "res: " << movingField[0][11].slimeNum << endl;
    // cout << "begin hole precess" << endl;
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
    // for(int y = 0; y < N; y ++){
    //     for(int x = 0; x < N; x ++){
    //         // cout << y << "," << x << " ";
    //         cout << movingField[y][x].slimeNum << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "res: " << movingField[0][11].slimeNum << endl;
    return make_pair(movingField,slimes);
}


vector<Output> makeHand(vector<vector<Place>> &handField, vector<Slime> &slimes){
    vector<Output> allHand;
    int cnt = 0;
    for(Slime sl: slimes){
        if(!sl.remain){
            cnt ++;
            continue;
        }
        for(int i = 0; i < 4; i ++){ //方向
            for(int j = 1; j <= sl.k + 1; j ++){//jump距離
                // cout << i << j << endl;
                int nextY = sl.y + dirY[i] * j;
                int nextX = sl.x + dirX[i] * j;
                int holeY = vecHole[sl.c].y;
                int holeX = vecHole[sl.c].x;
                if(inField(nextY, nextX)){
                    // cout << "place: " << sl.y << " " <<  sl.x << endl;
                    // cout << "after: " << nextY << " " << nextX << endl;
                    // cout << "hole: " << holeY << " " << holeX << endl;
                    // cout << "distance: " << placetoPlace[sl.y][sl.x][holeY][holeX] << " " << placetoPlace[nextY][nextX][holeY][holeX] << endl;
                    if(placetoPlace[sl.y][sl.x][holeY][holeX] >= placetoPlace[nextY][nextX][holeY][holeX]){
                        char dir = getDirection(sl.y, sl.x, nextY, nextX);
                        allHand.push_back(Output(sl.y, sl.x, sl.k, dir, j));
                    }

                }else{
                    break;
                }
            }
        }
    }
    // cout << "remain =" <<  K - cnt << endl;
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



int main(){
    cin >> N >> K;
    field = vector<vector<Place>>(N, vector<Place>(N));
    vecHole = vector<Hole>(K);

    // cout << "OK" << endl;
    vector<Slime> slimes;
    int cnt = 0;
    for(ll y = 0; y < N; y ++){
        string strC;
        cin >> strC;
        for(ll x = 0; x < N; x ++){
            field[y][x] = Place(strC[x]);
            if(field[y][x].slimeNum > 0){
                // cout << y << " " << x << " <=" << endl;
                slimes.push_back(Slime(y, x, (strC[x] - 'a'), 0, cnt));
                cnt ++;
            }
            if(field[y][x].hole >= 0){
                vecHole[field[y][x].hole] = Hole(y, x);
            }
        }
    }
    // cout << "Why" << endl;
    placetoPlace = makePlaceToPlace();
    // cout << "input is OK" << endl;
    // for(int y = 0; y < N; y ++){
    //     for(int x = 0; x < N; x ++){
    //         cout << placetoPlace[11][2][y][x] << " ";
    //     }
    //     cout << endl;
    // }
    // int handCnt = 0;
    while(true){
        // handCnt ++;
        // if(handCnt > 1){
        //     break;
        // }

        auto allhand = makeHand(field, slimes);
        // cout << "size = " << allhand.size() << endl;
        // cout << "slimeNum" << slimes.size() << endl;

        
        int min = INT_MAX;
        if(allhand.size() == 0){
            break;
        }
        int choice = 0;
        // cout << "size = " << allhand.size() << endl;
        
        for(int i = 0; i < allhand.size(); i ++){
            auto s = std::chrono::steady_clock::now();
            Output hand = allhand[i];
            vector<vector<Place>>nextField;
            vector<Slime> nextSlimes;
            tie(nextField, nextSlimes) = moveCopy(hand, field, slimes);
            int score = evaluateScore(nextField, nextSlimes);

            // cout << "score " << score << endl;

            if(score < min){
                min = score;
                choice = i;
            }
                    // auto e = std::chrono::steady_clock::now();
                    // cout << "time2; " << std::chrono::duration_cast<std::chrono::milliseconds>(e - s).count() << endl;;
        }

                
        allhand[choice].put();
        move(allhand[choice], field, slimes);
        // for(int y = 0; y < N; y ++){
        //     for(int x = 0; x < N; x ++){
        //         cout << field[y][x].slimeNum << " ";
        //     }
        //     cout << endl;
        // }
        
    }

    

}




