#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
using ll = long long int;
using vl = vector<ll>;

//direction 上から時計回りに0, 1, 2, 3
ll H, W;
vector<vector<char>> S;
vector<vector<vector<bool>>> memo;
vector<int> directionX = {0, 1, 0, -1}, directionY = {-1, 0, 1, 0}; 
vector<char> result;
vector<char> strs = {'U', 'R', 'D', 'L'};

bool search(ll x, ll y, ll nowDir){
    
    if(memo[y][x][nowDir]){
        return false;
    }
    memo[y][x][nowDir] = true;
    // cout << x << ", " << y << ", " << nowDir << endl;
    char place = S[y][x];
    
    ll newX, newY, newD;
    if(place == 'G'){
        return true;
    }
    if(place == '#'){
        return false;
    }
    
    if(place == 'o'){//同じ方向
        newD = nowDir;
        newX = x + directionX[newD];
        newY = y + directionY[newD];

        result.push_back(strs[newD]);
        if(search(newX, newY, newD)){
            return true;
        }
        memo[newY][newX][newD] = true;
        result.pop_back();
    }else if(place == 'x'){
        for(int dir = 0; dir < 4; dir ++){
            if(dir != nowDir){
                newD = dir;
                newX = x + directionX[newD];
                newY = y + directionY[newD];

                result.push_back(strs[newD]);
                if(search(newX, newY, newD)){
                    return true;
                }
                memo[newY][newX][newD] = true;
                result.pop_back();

            }
        }
    }else{
        
        for(int dir = 0; dir < 4; dir ++){
            newD = dir;
            newX = x + directionX[newD];
            newY = y + directionY[newD];
            

            result.push_back(strs[newD]);
            // cout << "OK" << endl;
            if(search(newX, newY, newD)){
                return true;
            }
            memo[newY][newX][newD] = true;
            result.pop_back();

        }
    }
    return false;
}

int main(){
    cin >> H >> W;
    S.resize(H + 2);
    S[0].resize(W + 2, '#');
    S[H + 1].resize(W + 2, '#');
    memo.resize(H + 2);
    memo[0].resize(W + 2, vector<bool>(4, false));
    memo[H + 1].resize(W + 2, vector<bool>(4, false));
    ll sX, sY;

    for(ll y = 1; y <= H; y ++){
        S[y].resize(W + 2, '#');
        memo[y].resize(W + 2, vector<bool>(4, false));
        for(ll x = 1; x <= W; x ++){
            // cout << y << x << endl;
            cin >> S[y][x];
            if(S[y][x] == 'S'){
                sX = x;
                sY = y;
            }
        }
    }
    for(ll i = 0; i < 4; i ++){
        if(search(sX, sY, i)){
            cout << "Yes" << endl;
            for(ll i = 0; i < result.size(); i ++){
                cout << result[i];
            }
            cout << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    

}