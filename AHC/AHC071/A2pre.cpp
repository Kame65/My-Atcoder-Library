#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;



ll W, H, K;
vl vecC;
vector<set<ll>> hole;
vvl ans;
map<pair<ll, ll>, bool> field;

void putBlock(ll x, ll y, ll blockLength){
    ans.push_back({x, y, blockLength});
    for(ll i = x; i <= x + blockLength - 1; i ++){
        field[make_pair(i, y)] = true;
    }
    if(y > 0){
        hole[y - 1].insert(x + (blockLength - 1) / 2);
    }
}




int main(){
    cin >> W >> H >> K;
    vecC = vl(5);
    for(ll i = 0; i < 5; i ++){
        cin >> vecC[i];
    }
    
    hole = vector<set<ll>>(H + 1);
    for(ll i = 0; i < K; i ++){
        ll a, b;
        cin >> a >> b;
        hole[b].insert(a);
    }

    ll beforeX = -1;
    for(ll y = H; y >= 0; y --){
        
        // cout << "y = " << y << endl;
        // for(ll x: hole[y]){
        //     cout << x << " ";
        // }
        // cout << endl;
        beforeX = -1;
        
        for(ll x: hole[y]){
            // cout << "x = " << x << endl;
            if(beforeX < 0 || field[make_pair(beforeX, y)]){
                beforeX = x;
            }else{
                ll pushX = beforeX;
                ll blockLength = 1;
                if(abs(beforeX - x) <= 8){
                    blockLength = (abs(beforeX - x) + 1) / 2 * 2 + 1;
                    if(beforeX + blockLength - 1 == W){
                        putBlock(beforeX, y, 1);
                        putBlock(x, y, 1);
                        
                    }else{
                        putBlock(beforeX, y, blockLength);
                        beforeX = -1;

                    }
                    
                }else{
                    putBlock(beforeX, y, 1);
                    beforeX = x;
                }

                // if(y != 0){
                //     // cout << "blockInfo: " << pushX << " " << y << " " << blockLength << " " << endl;
                //     // cout << "hole: " << pushX + (blockLength - 1) / 2 << " " << y - 1 << endl;
                //     hole[y - 1].insert(pushX + (blockLength - 1) / 2);
                // }
                
            }
            // cout << "last: " << (x == *hole[y].rbegin()) << " " << beforeX << " " << field[make_pair(beforeX, y)] << endl;
            if(x == *hole[y].rbegin() && (beforeX >= 0 && !field[make_pair(beforeX, y)])){
                // cout << "last change" << endl;

                ans.push_back({beforeX, y, 1});
                field[make_pair(beforeX, y)] = true;
                if(y > 0){
                    hole[y - 1].insert(beforeX);
                }
                
            }
            
        }
    }

    cout << ans.size() << endl;
    for(ll i = 0; i < ans.size(); i ++){
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
    }

    // cout << field[make_pair(43, 33)] << endl;
    

}