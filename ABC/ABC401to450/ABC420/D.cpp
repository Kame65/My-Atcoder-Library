#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long int;

int H, W;
vector<vector<char>>field, switchedField;
vector<vector<int>> memoField, memoSwitchedField;
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

int INF = INT_MAX;

ll getminWay(int beforeY, int beforeX, int y0, int x0, bool swi){
    vector<vector<char>>* nowField;
    
    if(!swi){
        nowField = &field;
        if(memoField[y0][x0] > 0){
            return memoField[y0][x0];
        }
    }else if(swi){
        nowField = &switchedField;
        if(memoSwitchedField[y0][x0] > 0){
            return memoField[y0][x0];
        }
    }else{
        if((*nowField)[y0][x0] == 'S'){
            return 0;
        }
        for(int idx = 0; idx < 4; idx ++){
            int x = x0 + dx[idx];
            int y = y0 + dy[idx];
            int min = INF;
            if((*nowField)[y][x] != '#' &&(x != beforeX || y != beforeY)){
                int way;
                if((*nowField)[y][x] == '?'){
                    way = getminWay(y0, x0, y, x, !swi);
                }else{
                    way = getminWay(y0, x0, y, x, swi);
                }
                if(min > way){
                    min = way;
                }
            }
        }
    }
}


int main(){
    field.resize(H + 2);
    switchedField.resize(H + 2);
    memoField.resize(H + 2);
    memoSwitchedField.resize(H + 2);
    field[0].resize(W + 2, '#');
    switchedField[0].resize(W + 2, '#');
    field[H + 1].resize(W + 2, '#');
    switchedField[H + 1].resize(W + 2, '#');
    for(int y = 1; y <= H; y ++){
        field[y].resize(W + 2, '#');
        switchedField[y].resize(W + 2, '#');
        memoField[y].resize(W + 2, -1);
        memoSwitchedField[y].resize(W + 2, -1);

        for(int x = 1; x <= W; x ++){
            char c;
            cin >> c;
            if(c == 'o'){
                field[y][x] = '.';
                switchedField[y][x] = '#';
            }else if(c == 'x'){
                field[y][x] = '#';
                switchedField[y][x] = '.';
            }else{
                field[y][x] = c;
                switchedField[y][x] = c;
            }
        }


    }


    
    
}