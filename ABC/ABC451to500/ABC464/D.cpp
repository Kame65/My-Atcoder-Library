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

ll getDpSunny(string& S, vl& vecX, vl&vecY, vl& dpRain, vl& dpSunny, ll day);
ll getDpRain(string& S, vl& vecX, vl& vecY, vl& dpRain, vl& dpSunny, ll day){
    if(dpRain[day] > 0){
        return dpRain[day];
    }
    if(day == 0){
        return 0;
    }
    if(S[day - 1] == 'R'){
        dpRain[day] = max(getDpRain(S, vecX, vecY, dpRain, dpSunny, day- 1), getDpSunny(S, vecX, vecY, dpRain, dpSunny, day- 1));
        return dpRain[day];
    }else{
        dpRain[day] = max(getDpRain(S, vecX, vecY, dpRain, dpSunny, day- 1), getDpSunny(S, vecX, vecY, dpRain, dpSunny, day- 1)) - vecX[day];
        return dpRain[day];
    }
    

}
ll getDpSunny(string& S, vl& vecX, vl&vecY, vl& dpRain, vl& dpSunny, ll day){
    if(dpSunny[day] > 0){
        return dpSunny[day];
    }
    if(day == 0){
        return 0;
    }
    if(S[day - 1] == 'S'){
        dpSunny[day] = max(getDpRain(S, vecX, vecY, dpRain, dpSunny, day - 1) + vecY[day - 1], getDpSunny(S, vecX, vecY, dpRain, dpSunny, day- 1));
        return  dpSunny[day];
    }else{
        
        dpSunny[day] = max((getDpRain(S, vecX, vecY, dpRain, dpSunny, day - 1) - vecX[day] + vecY[day - 1]), getDpSunny(S, vecX, vecY, dpRain, dpSunny, day- 1)- vecX[day]);
        // cout << "nowDay = " << day << endl;
        // cout << "way1: " << getDpRain(S, vecX, vecY, dpRain, dpSunny, day - 1) << endl;
        // cout << "way1: " << getDpRain(S, vecX, vecY, dpRain, dpSunny, day - 1) << endl;

        // cout << vecX[day] << ", " << vecY[day - 1] << endl;
        // cout << dpSunny[day] << endl;
        return dpSunny[day];
    }

}


void solveCase(){
    ll N;
    cin >> N;
    string S;
    cin >> S;
    vl vecX(N + 1);
    vl vecY(N);
    for(ll i = 1; i <= N; i ++){
        cin >> vecX[i];
    }
    for(ll i = 1; i <= N - 1; i ++){
        cin >> vecY[i];
    }
    vl dpRain(N + 1, -1), dpSunny(N + 1, -1);
    // cout << vecY[2] << endl;
    // cout << getDpRain(S, vecX, vecY, dpRain, dpSunny, 3) << endl;;
    // cout << getDpSunny(S, vecX, vecY, dpRain, dpSunny, 3) << endl;
    // cout << getDpRain(S, vecX, vecY, dpRain, dpSunny, 3 - 1) - vecX[3] + vecY[3 - 1];
    cout << max(getDpRain(S, vecX, vecY, dpRain, dpSunny, N), getDpSunny(S, vecX, vecY, dpRain, dpSunny, N)) << endl;


}

int main(){
    ll T;
    cin >> T;
    for(ll i = 0; i < T; i ++){
        solveCase();
    }
    
}