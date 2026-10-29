#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include<tuple>
using namespace std;
using ll = long long int;


int H, W;
vector<vector<char>> field;
vector<vector<int>> memoField;
map<char, vector<tuple<int, int>>> memoObj;
map<int, vector<tuple<int, int>>> memoPlac;
vector<int> nextX = {-1, 0, 1, 0};
vector<int>nextY = {0, -1, 0, 1};

void success(int num, int nowX, int nowY, char c){
    // cout << num << ", " << nowX << ", " << nowY << ", " << c << endl;

    for(int j = 0; j < 4; j ++){
        int nX = nowX + nextX[j];
        int nY = nowY + nextY[j];
        if(0 <= nX && nX < W && 0 <= nY && nY < H){//範囲内確認
            if(field[nY][nX] != '#' && memoField[nY][nX] == -1){
                memoPlac[num + 1].push_back(make_tuple(nY, nX));
                memoField[nY][nX] = num + 1;
            }
        }
    }

    if(c != '.'){//teleport処理
        for(int i = 0; i < memoObj[c].size(); i ++){
            int y, x;
            tie(y, x) = memoObj[c][i];
            // cout << x << ", " << y << endl;
            if(memoField[y][x] == -1){
                memoPlac[num + 1].push_back(make_tuple(y, x));
                memoField[y][x] = num + 1;
            }
        }
        memoObj[c].clear();
    }

}

int main(){
    cin >> H >> W;
    field.resize(H);
    memoField.resize(H);
    for(int i = 0; i < H; i ++){
        field[i].resize(W);
        memoField[i].resize(W, -1);
    }
    for(int h = 0; h < H; h ++){
        for(int w = 0; w < W; w ++){
            cin >> field[h][w];
            if(field[h][w] != '.' && field[h][w] != '#'){
                memoObj[field[h][w]].push_back(make_tuple(h, w));
            }
        }
    }
    memoField[H - 1][W - 1] = 0;
    memoPlac[0].push_back(make_tuple(H - 1, W - 1));
    int i = 0;
    while(memoPlac[i].size() != 0){
        for(int j = 0; j < memoPlac[i].size(); j ++){
            int y, x;
            tie(y, x) = memoPlac[i][j];
            success(i, x, y, field[y][x]);
        }
        i ++;
    }
    
    cout << memoField[0][0] << endl;

}