#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;



ll H, W, N;
vvl field, sumField, results;
vector<vector<pair<ll, ll>>> rDownField;

int main(){
    cin >> H >> W >> N;
    field = vvl(H + 2, vl(W + 2, 1));
    sumField = vvl(H + 2, vl(W + 2, 1));
    for(ll i = 0; i < N; i ++){
        ll a, b;
        cin >> a >> b;
        field[a][b] = 0;
    }
    sumField[0] = vl(W + 2, 0);
    sumField[H + 1] = vl(W + 2, 0);
    for(ll y = 0; y <= H + 1; y ++){
        sumField[y][0] = 0;
        sumField[y][W + 1] = 0;
    }
    for(ll y = 1; y <= H; y ++){
        for(ll x = 1; x <= W; x ++){
            sumField[y][x] = field[y][x] + sumField[y - 1][x] + sumField[y][x - 1] - sumField[y - 1][x - 1];
            // cout << sumField[y][x] << " ";
        }
        // cout << endl;
    }

    rDownField = vector<vector<pair<ll, ll>>>(H + 2, vector<pair<ll, ll>>(W + 2, make_pair(0, 0)));
    results = vvl(H + 1, vl(W + 1));
        for(ll y0 = 1; y0 <= H; y0 ++){
            for(ll x0 = 1; x0 <= W; x0 ++){
                ll beforeX, beforeY;
                tie(beforeY, beforeX) = rDownField[y0 - 1][x0 - 1];
                ll y = max(beforeY, y0), x = max(beforeX, x0);
                // if(y0 == 3 && x0 == 2){
                //     cout << y << ", " << x << endl;
                //     cout << "sumFin " << sumField[y][x] + sumField[y0 - 1][x0 - 1] - sumField[y0 - 1][x] - sumField[y][x0 - 1] << endl;
                //     cout << "aim:  " << (y - y0 + 1) * (y - y0 + 1) << endl;
                // }
                
                // cout <<  "y0, x0 = " << y0 << " " << x0 << endl;
                // cout << "y, x = " << y << ", " << x << endl;
                // cout << "sumFin " << sumField[y][x] + sumField[y0 - 1][x0 - 1] - sumField[y0 - 1][x] - sumField[y][x0 - 1] << endl;
                // cout << "aim:  " << (y - y0 + 1) * (y - y0 + 1) << endl;
                while(sumField[y][x] + sumField[y0 - 1][x0 - 1] - sumField[y0 - 1][x] - sumField[y][x0 - 1] == (y - y0 + 1) * (y - y0 + 1)){
                    // if(y0 == 2 && x0 == 3){
                    // cout << "sumFin " << sumField[y][x] + sumField[y0 - 1][x0 - 1] - sumField[y0 - 1][x0] - sumField[y0][x0 - 1] << endl;
                    // cout << "aim:  " << (y - y0 + 1) * (y - y0 + 1) << endl;
                    // }
                    y ++;
                    x ++;
                    
                    
                }
                // cout << y << ", " << x << endl;
                rDownField[y0][x0] = make_pair(y - 1, x - 1);
                results[y0][x0] = y - y0 ;

            }
            // cout << endl;
    }
    // for(ll y = 1; y <= 5; y ++){
    //     for(ll x = 1; x <= 5; x ++){
    //         // sumField[y][x] = field[y][x] + sumField[y - 1][x] + sumField[y][x - 1] - sumField[y - 1][x - 1];
    //         cout << rDownField[y][x].first << "," << rDownField[y][x].second << ": " << results[y][x] << "  ";
    //     }
    //     cout << endl;
    // }

    // for(ll y = 1; y <= 10; y ++){
    //     for(ll x = 1; x <= 10; x ++){
    //         cout << results[y][x] << " ";
    //     }
    //     cout << endl;
    // }
    ll ans = 0;
    for(ll y = 1; y <= H; y ++){
        for(ll x = 1; x <= W; x ++){
            // sumField[y][x] = field[y][x] + sumField[y - 1][x] + sumField[y][x - 1] - sumField[y - 1][x - 1];
            ans += results[y][x];
        }
    }
    cout << ans << endl;
    



    
    
}