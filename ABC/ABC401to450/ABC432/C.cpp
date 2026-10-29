#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>
using namespace std;
using ll = long long int;

ll N, X, Y, result;
vector<ll> listA, weightList;

ll maxVal(ll wheight){//O(N)
    ll sumB = 0;
    for(ll i = 0; i < N; i ++){
        sumB += (wheight - listA[i] * X) / (Y - X);

    }
    return sumB;
}

bool weightOK(ll wheight){//O(N)
    for(ll i = 0; i < N; i ++){
        if(wheight - listA[i] * X < 0){
            return false;
        }
        if((wheight - listA[i] * X) % (Y - X) != 0){
            return false;
        }
    }
    return true;
}


int main(){
    cin >> N >> X >> Y;
    listA.resize(N);
    for(ll i = 0; i < N; i ++){
        cin >> listA[i];
    }
    sort(listA.begin(), listA.end());
    //初期化OK
    
    ll min, max, l, r, mid;
    l = X * listA[N - 1];
    r = Y * listA[0];
    if(r - l < 0){
        cout << -1 << endl;
        return 0;
    }

    for(ll i = r; i >= l; i --){
        if(weightOK(i)){
            cout << maxVal(i) << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    

}