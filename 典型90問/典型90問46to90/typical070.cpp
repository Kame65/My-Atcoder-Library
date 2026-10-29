#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <map>


using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vvvl  = vector<vvl>;


ll N;
vl vecX, vecY;
vl cumSumStartX, cumSumEndX;
vl cumSumStartY, cumSumEndY;
ll fx(ll x){
    ll result = 0;
    auto iterP = upper_bound(vecX.begin(), vecX.end(), x);//x以上の最小値
    ll num = (iterP - vecX.begin());// x以下の個数
    // cout << "num = " << num << endl;
    result -= cumSumStartX[num];
    // cout << result << endl;
    result += x * num;
    // cout << result << endl;
    result += cumSumEndX[N - num];
    // cout << result << endl;
    result -= x * (N - num);
    // cout << "result : " << result << endl;
    return result;
    
}
ll fy(ll x){
    ll result = 0;
    auto iterP = upper_bound(vecY.begin(), vecY.end(), x);//x以上の最小値
    ll num = (iterP - vecY.begin());// x以下の個数
    // cout << "num = " << num << endl;
    result -= cumSumStartY[num];
    // cout << result << endl;
    result += x * num;
    // cout << result << endl;
    result += cumSumEndY[N - num];
    // cout << result << endl;
    result -= x * (N - num);
    // cout << "result : " << result << endl;
    return result;
    
}
int main(){
    cin >> N;
    vecX = vl(N);
    vecY = vl(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecX[i] >> vecY[i];
    }
    sort(vecX.begin(), vecX.end());
    sort(vecY.begin(), vecY.end());
    cumSumStartX = vl(N + 1, 0), cumSumEndX = vl(N + 1, 0);
    cumSumStartY = vl(N + 1, 0), cumSumEndY = vl(N + 1, 0);
    for(ll i = 1; i <= N; i ++){
        cumSumStartX[i] = vecX[i - 1] + cumSumStartX[i - 1];
        cumSumStartY[i] = vecY[i - 1] + cumSumStartY[i - 1];
        ll endIdx = N - i;
        cumSumEndX[i] = vecX[endIdx] + cumSumEndX[i - 1];
        cumSumEndY[i] = vecY[endIdx] + cumSumEndY[i - 1];
    }
    // ll lowX, highX;
    // ll c1X, c2X;
    // lowX = -1e9 - 1;
    // highX = 1e9 + 1;
    // c1X = (lowX * 2 + highX) / 3;//1:2に内分
    // c2X = (lowX + highX * 2) / 3;
    // while(c2X - c1X > 1){
    //     // cout << fx(c1X) << ", " << fx(c2X) << endl;
    //     if(fx(c1X) < fx(c2X)){
    //         highX = c2X;
    //     }else if(c1X == c2X){
    //         lowX = c1X;
    //         highX = c2X;
    //     }else{
    //         lowX = c1X;
    //     }
    //     c1X = (lowX * 2 + highX) / 3;//1:2に内分
    //     c2X = (lowX + highX * 2) / 3;
    // }

    // ll lowY, highY;
    // lowY = -1e9 - 1;
    // highY = 1e9 + 1;
    // ll c1Y, c2Y;
    // c1Y = (lowY * 2 + highY) / 3;//1:2に内分
    // c2Y = (lowY + highY * 2) / 3;
    // while((c2Y - c1Y > 1)){
    //     // cout << fy(c1Y) << ", " << fy(c2Y) << endl;
    //     if(fy(c1Y) < fy(c2Y)){
    //         highY = c2Y;
    //     }else if(c1Y == c2Y){
    //         lowY = c1Y;
    //         highY = c2Y;
    //     }else{
    //         lowY = c1Y;
    //     }
    //     c1Y = (lowY * 2 + highY) / 3;//1:2に内分
    //     c2Y = (lowY + highY * 2) / 3;
    // }
    ll costX = fx(vecX[N/2]);
    ll costY = fy(vecY[N/2]);
    // cout << c1X << ", " << fx(c1X) << endl;
    // cout << c1Y << ", " << fy(c1Y) << endl;
    cout << costX + costY << endl;
    return 0;

}