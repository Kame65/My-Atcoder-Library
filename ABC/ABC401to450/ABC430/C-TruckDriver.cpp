#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long int;

ll N, A, B, result;
vector<int> listAB, maxSizeL, minSizeL;


bool moveRight(ll& myLeft, ll& myRight, ll& countA, ll& countB){
    if(myRight >= N - 1){
        return false;//右に移動できない;
    }else{
        myRight += 1;
        if(listAB[myRight] > 0){
            countA += 1;
        }else{
            countB += 1;
        }
        return true;
    }
}
bool moveLeft(ll& myLeft, ll& myRight, ll& countA, ll& countB){
    if(listAB[myLeft] > 0){
        countA -= 1;
    }else{
        countB -= 1;
    }
    myLeft += 1;
    return true;
}

void makeMaxSizeL(){//Lから始まる最大サイズの満たす配列の長さを得る。
    //初期化
    ll countA = 0;
    ll countB = 0;
    ll myLeft = 0;
    ll myRight = 0;
    if(listAB[0] == 1){
        countA += 1;
    }else{
        countB += 1;
    }
    while(1){
        if(countA >= A){//A以上を満たす
            if(countB >= B){
                moveLeft(myLeft, myRight, countA, countB);
            }else{
                maxSizeL[myLeft] = myRight - myLeft + 1;
                if((countB == B - 1 && listAB[myRight + 1] < 0)||myRight == N - 1){//次右を動かすと条件を満たさないとき
                    moveLeft(myLeft, myRight, countA, countB);
                }
                else if(!moveRight(myLeft, myRight, countA, countB)){
                    break;
                }
            }
        }else{
            if(!moveRight(myLeft, myRight, countA, countB)){
                break;
            }
        }
    }
    return;

}

void makeMinSizeL(){//Lから始まる最大サイズの満たす配列の長さを得る。
    //初期化
    ll countA = 0;
    ll countB = 0;
    ll myLeft = 0;
    ll myRight = 0;
    if(listAB[0] == 1){
        countA += 1;
    }else{
        countB += 1;
    }
    
    while(1){
        if(countA >= A){//A以上を満たす
            if(countB >= B){
                moveLeft(myLeft, myRight, countA, countB);
            }else{
                minSizeL[myLeft] = myRight - myLeft + 1;
                moveLeft(myLeft, myRight, countA, countB);
            }
        }else{
            if(!moveRight(myLeft, myRight, countA, countB)){
                break;
            }
        }
    }
    return;

}


int main(){
    cin >> N >> A >> B;
    listAB.resize(N + 1, 0);
    for(ll i = 0; i < N; i ++){
        char c;
        cin >> c;
        if(c == 'a'){
            listAB[i] = 1;
        }else{
            listAB[i] = -1;
        }   
    }
    maxSizeL.resize(N, -1);
    minSizeL.resize(N, -1);
    result = 0;

    makeMaxSizeL();
    makeMinSizeL();

    for(ll i = 0; i < N; i ++){
        if(maxSizeL[i] > 0){
            result += maxSizeL[i] - minSizeL[i] + 1;
        }
    }

    for(int i = 0; i < N; i ++){
        cout << maxSizeL[i] << ", ";
    }
    cout << endl;
    for(int i = 0; i < N; i ++){
        cout << minSizeL[i] << ", ";
    }
    cout << result << endl;

}
