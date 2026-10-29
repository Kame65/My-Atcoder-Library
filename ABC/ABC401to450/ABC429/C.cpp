#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

ll N, total;
vector<ll> listA, counts;

int main(){
    cin >> N;
    listA.resize(N);
    for(int i = 0; i < N; i ++){
        cin >> listA[i];
    }
    counts.resize(N + 1, 0);
    for(int i = 0; i < N; i ++){
        counts[listA[i]] += 1;
    }
    total = 0;
    for(int i = 1; i < N + 1; i ++){
        if(counts[i] > 0){
            total += counts[i] * (counts[i] - 1) / 2 * (N - counts[i]); 
        }   
    }
    cout << total << endl;

}
