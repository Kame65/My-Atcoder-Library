#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <queue>

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vvvl  = vector<vvl>;



ll H, W;
ll rs, cs, rt, ct;
vvc field;

vvvl minField;
vl dirX = {-1, 0, 1, 0};
vl dirY = {0, 1, 0, -1};



int main(){
    cin >> H >> W;
    cin >> rs >> cs >> rt >> ct;
    field = vvc(H + 2, vc(W + 2, '#'));
    for(ll y = 1; y <= H; y ++){
        for(ll x = 1; x <= W; x ++){
            cin >> field[y][x];
        }
    }
    minField = vvvl(H + 2, vvl(W + 2, vl(4, H * W + 1)));//[y][x][dir];
    minField[rs][cs] = vl(4, -1);

    queue<pair<ll, ll>> places;
    places.push(make_pair(cs, rs));
    // for(ll y = 1; y <= H; y ++){
    //     for(ll x = 1; x <= W;x ++){
    //         cout << *min_element(minField[y][x].begin(), minField[y][x].end()) << " ";
    //     }
    //     cout << endl;
    // }
    while(places.size() > 0){
        
        ll px, py;
        
        tie(px, py) = places.front();
        // cout << "px, py = " << px << " " << py << endl;
        places.pop();
        for(ll i = 0; i < 4; i ++){
            ll nextX = px + dirX[i], nextY = py + dirY[i];
            // cout << "next: " << nextX << ", " << nextY << endl;
            ll cnt = minField[py][px][i];
            while(field[nextY][nextX] != '#'){

                if(minField[nextY][nextX][i] > cnt){
                    minField[nextY][nextX][i] = cnt + 1;
                    for(ll j = 0; j < 4; j ++){
                        if(minField[nextY][nextX][j] > cnt + 1){
                            minField[nextY][nextX][j] = cnt + 1;
                        }
                    }
                    places.push(make_pair(nextX, nextY));
                    nextX += dirX[i];
                    nextY += dirY[i];
                }else{
                    break;
                }
            }
        }
    }
    // for(ll y = 1; y <= H; y ++){
    //     for(ll x = 1; x <= W;x ++){
    //         cout << *min_element(minField[y][x].begin(), minField[y][x].end()) << " ";
    //     }
    //     cout << endl;
    // }
    cout << *min_element(minField[rt][ct].begin(), minField[rt][ct].end()) << endl;






}