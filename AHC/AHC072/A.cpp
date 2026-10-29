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
    bool ground;
    int slimeNum;
    int hole;
    vector<int> slime;
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
                    slime.push_back(c - 'a');
                }else{
                    slimeNum = 0;
                }
            }
            
        }
    }
};

struct Output{
    int x;
    int y;
    int k;
    char dir;
    int dis;
    Output(int y_, int x_, int k_, char dir_, int dis_){
        x = x_;
        y = y_;
        k = k_;
        dir = dir_;
        dis = dis_;
    }

    void put(){
        cout << y << " " << x << " " << k << " " << dir << " " << dis << endl;
    }
};

vector<vector<Place>> field;

Place NONE = Place('.');
vector<int> dirX = {-1, 0, 1, 0}, dirY = {0, 1, 0, -1};
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

// i_0, j_0, k_0, d_0, l_0;
vector<Output> makeRouteBFS(int beginY, int beginX, int color){
    // cout << "in make BFS" << endl;
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
                if(nowX == -3){
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
                int jump = field[nowY][nowX].slimeNum;
                if(nowX == beginX && nowY == beginY){
                    jump --;
                }
                result.push_back(Output(nowPlace.first, nowPlace.second, jump, dir, dist));
                // cout << "add: " << nowPlace.first << " " << nowPlace.second << endl;

            }
        }

        int jumpPower = field[nowY][nowX].slimeNum + 1; //jumpできる距離
        if(nowY == beginY && nowX == beginX){
            jumpPower = 1;
        }
        
        for(int i = 0; i < 4; i ++){
            for(int j = 1; j <= jumpPower; j ++){
                int nextY = nowY + dirY[i] * j;
                int nextX = nowX + dirX[i] * j;
                if(inField(nextY, nextX) && already[nextY][nextX].first == -1){//壁がないかつ未探索
                    searchQ.push(make_pair(nextY, nextX));
                    already[nextY][nextX] = make_pair(nowY, nowX);
                }else{
                    break;
                }
            }
            
        }
        
    }
    return vector<Output>();
    
}



int main(){
    cin >> N >> K;
    field = vector<vector<Place>>(N, vector<Place>(N));
    vector<pair<int, int>> slimePlace;
    vector<pair<int, int>> vecHole(K); //それぞれのスライムの帰る位置
    for(ll y = 0; y < N; y ++){
        string strC;
        cin >> strC;
        for(ll x = 0; x < N; x ++){
            field[y][x] = Place(strC[x]);
            if(field[y][x].hole >= 0){
                vecHole[field[y][x].hole] = make_pair(y, x);
            }
            if(field[y][x].slimeNum > 0){
                // cout << y << " " << x << " <=" << endl;
                slimePlace.push_back(make_pair(y, x));
            }
        }
    }
    // cout << "input is OK" << endl;

    for(auto place: slimePlace){// 全てのスライムに対して
        int y = place.first;
        int x = place.second;
        // cout << "makeRoute: " << y << " " << x << endl;
        auto oneResult = makeRouteBFS(y, x, field[y][x].slime[0]);

        field[y][x].slimeNum --;
        field[y][x].slime.pop_back();
        for(auto out: oneResult){
            out.put();
        }   
    }
}




