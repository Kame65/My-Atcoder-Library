#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;
using ll = long long;

ll N, K;



// field[y][x]

// class Place{
//     public:
//     bool ground;
//     int slimeNum;
//     int hole;
//     vector<int> slime;
//     Place(char c){
//         if(c == '#'){
//             slimeNum = 0;
//             ground = false;
//             hole = -1;
//         }else{
//             ground = true;
//             if(c - 'A' >= 0){
//                 hole = c - 'A';
//                 slimeNum = 0;
//             }else{
//                 hole = -1;
//                 if(c - 'a' >= 0){
//                     slimeNum = 1;
//                     slime.push_back(c - 'a');
//                 }
//             }
            
//         }
//     }


// };



class Slime{
    public:
    int x, y; //座標
    int color ; // 色 a-> 0 b -> 1など
    int height; //下にいるスライムの数
    int topNum, bottomNum;
    Slime* upper;
    Slime* lower;
    int distX, distY;

    Slime(){
        x = -1; y = -1;
        color = -1;
        height = -1;
    }

    Slime(ll y_, ll x_, ll c_, ll h_){
        x = x_;
        y = y_;
        color = c_;
        height = h_;
        upper = &Slime();
        lower = &Slime();
        topNum = 0;
        bottomNum = 0;
    }

    void setDistByHole(int holeY, int holeX){
        distY = abs(y - holeY);
        distX = abs(x - holeX);
    }
};

vector<vector<char>> field;
vector<pair<int, int>> hole;


int main(){
    cin >> N >> K;
    vector<vector<Slime>> slimes(K);
    field = vector<vector<char>>(N, vector<char>(N));
    hole = vector<pair<int, int>>(K);
    vector<pair<int, int>> vecHole(K); //それぞれのスライムの帰る位置
    for(ll y = 0; y < N; y ++){
        string strC;
        cin >> strC;
        for(ll x = 0; x < N; x ++){
            if(strC[x] == '#'){
                field[y][x] = '#';
            }else{
                field[y][x] = '.';
            }
            if('a' <= strC[x] && strC[x] <= 'z'){//slime
                slimes[strC[x]].push_back(Slime(y, x, field[y][x] - 'a', 0));
            }

            if('A' <= strC[x] && strC[x] <= 'Z'){//hole
                hole[strC[x] - 'A'] = make_pair(y, x);
            }
        }
    }

    for(int c = 0; c < K; c++){
        for(int i = 0; i < slimes[c].size(); i ++){
            int holeY, holeX;
            tie(holeY, holeX) = hole[c];
            slimes[c][i].setDistByHole(holeY, holeX);
        }
    }





}