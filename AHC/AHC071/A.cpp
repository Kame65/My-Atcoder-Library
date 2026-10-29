#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;







ll W, H, K;
vl vecC;
vvl point;
vvl ans;




int main(){
    cin >> W >> H >> K;
    vecC = vl(5);
    for(ll i = 0; i < 5; i ++){
        cin >> vecC[i];
    }
    
    point = vvl(K, vl(3));
    for(ll i = 0; i < K; i ++){
        point[i][0] = i;
        cin >> point[i][1] >> point[i][2];
    }

    // y座標降順sort
    sort(point.begin(),point.end(),[](const vector<ll> &alpha,const vector<ll> &beta){if(alpha[2] > beta[2]){return true;}else if(alpha[2] == beta[2] && alpha[1] < beta[1])return true;else{return false;}});
    vl prev(K, 0);
    ll ymax = point[0][2];
    ll beforeX = -1;
    for(ll i = 0; i < K; i ++){
        cout << "beforeX = " << beforeX << endl;
        cout << "x, y = " << point[i][1] << " " << point[i][2] << endl;
        if(ymax == point[i][2]){
            if(beforeX > 0){
                if(abs(beforeX - point[i][1]) <= 9){
                    ll blockLength = (abs(beforeX - point[i][1]) + 1) / 2 * 2 + 1;
                    ans.push_back({beforeX, ymax, blockLength});
                    beforeX = -1;
                }else{
                    ans.push_back({beforeX, ymax, 1});
                    beforeX = point[i][1];
                }

            }else{
                beforeX = point[i][1];
            }
            
        }else{
            break;
        }
    }

    cout << ans.size() << endl;
    for(ll i = 0; i < ans.size(); i ++){
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
    }
    












    

}