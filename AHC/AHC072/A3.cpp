#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;
using ll = long long;

ll N, K;



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
    int k;
    char dir;
    int dis;
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
vector<vector<Place>> field;

Place NONE = Place('.');
vector<int> dirX = {-1, 0, 1, 0}, dirY = {0, -1, 0, 1};
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

vector<vector<Place>> move(Output , vector<vector<Place>>&, vector<Slime>&);
// i_0, j_0, k_0, d_0, l_0;
vector<Output> makeRouteBFS(int id, vector<vector<Place>>& field, vector<Slime>& slimes){//ここにいるスライムにのみ指示で巣に返す, heightはスライム一匹の時1
    // cout << "in make BFS" << endl;
    Slime sl = slimes[id];
    int beginY = sl.y;
    int beginX = sl.x;
    int color = slimes[id].c;
    int height = slimes[id].k;
    // cout << "info: " << beginY << " " << beginX << " " << color << " " << height  << endl;
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
        if(field[nowY][nowX].hole == color){
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
                    // int jump = field[beginY][beginX].slimeNum;
                    // result.push_back(Output(beginY, beginX, jump, dir, dist));


                    reverse(result.begin(), result.end());
                    return result;
                }
                char dir = getDirection(nowY, nowX, afterY, afterX);
                int dist = getDist(nowY, nowX, afterY, afterX);
                int remain = field[nowY][nowX].slimeNum;//残っているスライムの数
                if(nowX == beginX && nowY == beginY){
                    // cout << "What" << endl;
                    remain = height;
                    move(Output(nowPlace.first, nowPlace.second, remain, dir, dist), field, slimes);
                    // cout << "move is OK" << endl;
                    if(field[afterY][afterX].hole != color){// hole==colorの場合はmove()でスライムが消されるため必要なし
                        field[afterY][afterX].slimeNum --;
                        field[afterY][afterX].slimeId.pop_back();
                    }
                    
                }
                result.push_back(Output(nowPlace.first, nowPlace.second, remain, dir, dist));
                // cout << "add: " << nowPlace.first << " " << nowPlace.second << endl;

            }
        }

        int jumpPower = field[nowY][nowX].slimeNum + 1; //jumpできる距離
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


int evaluateScore(vector<vector<Place>> field, vector<Slime> slimes){
    int result = 0;
    
    for(Slime sl: slimes){
        if(sl.y >= 0){// スライムがいる
            result += makeRouteBFS(sl.id, field, slimes).size();
        }
        // result += makeRouteBFS(sl.y, sl.x, sl.c, field).size();
    }
    return result;
}


vector<vector<Place>> move(Output choice, vector<vector<Place>> &movingField, vector<Slime> &slimes){
    // cout << "in Move" << endl;
    int y = choice.y;
    int x = choice.x;
    int nextY = y + dirY[choice.dirNum];
    int nextX = x + dirX[choice.dirNum];
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
        movingField[nextY][nextX].slimeId.push_back(movingField[y][x].slimeId.back());
        movingField[y][x].slimeId.pop_back();
    }
    // cout << "begin hole precess" << endl;
    while(movingField[nextY][nextX].slimeId.back() == movingField[y][x].hole){// 
        int id = movingField[nextY][nextX].slimeId.back();
        if(movingField[y][x].hole != slimes[id].c){
            break;
        }
        movingField[nextY][nextX].slimeNum --;
        movingField[nextY][nextX].slimeId.pop_back();
        slimes[id].remain = false;
    }
    return movingField;
}



pair<vector<vector<Place>>, vector<Slime>> moveCopy(Output choice, vector<vector<Place>> movingField, vector<Slime> slimes){
    // cout << "in Move" << endl;
    int y = choice.y;
    int x = choice.x;
    int nextY = y + dirY[choice.dirNum];
    int nextX = x + dirX[choice.dirNum];
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
        movingField[nextY][nextX].slimeId.push_back(movingField[y][x].slimeId.back());
        movingField[y][x].slimeId.pop_back();
    }
    // cout << "begin hole precess" << endl;
    while(movingField[nextY][nextX].slimeId.back() == movingField[y][x].hole){// 
        int id = movingField[nextY][nextX].slimeId.back();
        if(movingField[y][x].hole != slimes[id].c){
            break;
        }
        movingField[nextY][nextX].slimeNum --;
        movingField[nextY][nextX].slimeId.pop_back();
        slimes[id].remain = false;
    }
    return make_pair(movingField,slimes);
}


vector<Output> makeHand(vector<vector<Place>> &handField, vector<Slime> &slimes){
    vector<Output> allHand;
    for(int y = 0; y < N; y ++){
        for(int x = 0; x < N; x ++){
            Place p = handField[y][x];
            if(p.slimeNum > 0){
                for(int sNum = 0; sNum < p.slimeId.size(); sNum ++){
                    int jumpPower = sNum + 1;
                    for(int i = 0; i < 4; i ++){
                        for(int j = 1; j <= jumpPower; j ++){
                            int nextY = y + dirY[i] * j;
                            int nextX = x + dirX[i] * j;
                            if(inField(nextY, nextX)){//壁がない
                                for(int k = jumpPower - 1; k >= 0; k --){
                                    if(handField[nextY][nextX].slimeNum + handField[y][x].slimeNum - k > 8){
                                        break;
                                    }
                                    char dir = getDirection(y, x, nextY, nextX);
                                    allHand.push_back(Output(y, x, k, dir, j));

                                }
                            }else{
                                break;
                            }
                        }
            
                    }
                }
            }
        }
    }
    return allHand;

}



int main(){
    cin >> N >> K;
    field = vector<vector<Place>>(N, vector<Place>(N));
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
        }
    }
    // cout << "input is OK" << endl;

    while(true){
        auto allhand = makeHand(field, slimes);
        int min = INT_MAX;
        if(allhand.size() == 0){
            break;
        }
        int choice = 0;
        for(int i = 0; i < allhand.size(); i ++){
            Output hand = allhand[i];
            vector<vector<Place>>nextField;
            vector<Slime> nextSlimes;
            tie(nextField, nextSlimes) = moveCopy(hand, field, slimes);
            int score = evaluateScore(nextField, nextSlimes);
            if(score < min){
                min = score;
                choice = i;
            }
        }
        allhand[choice].put();
    }

    

}




