#include <iostream> 
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;
using ll = long long int;



ll H, W;
queue<pair<ll, ll>> blackList;
vector<vector<int>> field, beforeField;

vector<int>aroundX = {-1, 0, 1, 0};
vector<int>aroundY = {0, 1, 0, -1};

bool judge(ll y, ll x){
    int countBlack = 0;
    for(int idx = 0; idx < 4; idx ++){
        int dx, dy;
        dy = aroundY[idx];
        dx = aroundX[idx];
        // cout << y + dy << " " << x + dx << endl;
        if(1 <= y && y <= H && 1 <= x && x <= W){
            // cout << y + dy << " " << x + dx << endl;
            if (beforeField[y + dy][x + dx] == 1){
                countBlack += 1;
            }
        }
    }
    if(countBlack == 1){
        return true;
    }else{
        return false;
    }
}

int main(){
    cin >> H >> W;
    field.resize(H + 2);
    field[0].resize(W + 2, -1);
    field[H + 1].resize(W + 2, -1);
    for(ll y = 1; y <= H; y ++){
        field[y].resize(W + 2, -1);
        for(ll x = 1; x <= W; x ++){
            char c;
            cin >> c;
            if(c == '.'){
                field[y][x] = 0;
            }else{
                field[y][x] = 1;
                pair<ll, ll> place = make_pair(y, x);
                blackList.push(place);
                
                
            }
        }
    }
    //field[y][x] = 1 -> black, = 0 -> white
    ll searchCount = 0;
    bool changeSearch = true;
    ll searchSize;
    int countChange = 0;
    while(blackList.size() > 0){
        
        if(changeSearch){

            beforeField = field;//TLE?
            searchSize = blackList.size();
            changeSearch = false;
            // cout << countChange << endl;
            // for(ll y = 1; y <= H; y ++){
            //     for(ll x = 1; x <= W; x ++){
            //         cout << field[y][x];
            //     }
            //     cout << endl;
            // }
            // cout << endl << endl;
            countChange ++;
        }
        searchSize --;
        if(searchSize == 0){
            changeSearch = true;
        }
        

        pair<ll, ll>place = blackList.front();
        blackList.pop();
        ll y0 = place.first;
        ll x0 = place.second;
        for(int idx = 0; idx < 4; idx ++){
            ll y = y0 + aroundY[idx];
            ll x = x0 + aroundX[idx];
            if(field[y][x] == 0 && judge(y, x)){
                field[y][x] = 1;
                pair<ll, ll>place = make_pair(y, x);
                blackList.push(place);
                cout << "x, y = " << x << " " << y << endl;
            }
        }
    }
    ll result = 0;
    for(ll y = 1; y <= H; y ++){
        for(ll x = 1; x <= W; x ++){
            if(field[y][x] == 1){
                result += 1;
            }
        }
    }
    // for(ll y = 1; y <= H; y ++){
    //     for(ll x = 1; x <= W; x ++){
    //         cout << field[y][x];
    //     }
    //     cout << endl;
    // }
    cout << result << endl;
}