#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long int;

ll N, M, K;
vector<ll> listH, listB;



int main(){
    cin >> N >> M >> K;

    for(ll i = 0; i < N; i ++){
        ll h;
        cin >> h;
        listH.push_back(h);
    }
        for(ll i = 0; i < M; i ++){
        ll b;
        cin >> b;
        listB.push_back(b);
    }
    sort(listB.begin(), listB.end());
    sort(listH.begin(), listH.end());

    // for(ll i = 0; i < M; i ++){
    //     cout << listB[i] << ", ";
        
    // }
    // cout << endl;

    for(ll i = 0; i < K; i ++){
        if(listB[M - K + i] - listH[i] < 0){
            cout << "No" << endl;
            // cout << i << ", " << listB[M - K + i] << ", " << listH[i] << endl;;
            return 0;
        }
    }
    cout << "Yes" << endl;

}