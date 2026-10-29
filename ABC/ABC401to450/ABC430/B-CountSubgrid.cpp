#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long int;

ll N, M;
vector<vector<ll>> listS, listM;
vector<vector<vector<ll>>> memoListM;

int inMemo(vector<vector<ll>>& list){
    bool result = false;//
    for(size_t i = 0; i < memoListM.size(); i ++){
        bool oneResult = true;//iのlistが一致しているか
        for(ll y = 0; y < M; y ++){
            for(ll x = 0; x < M; x ++){
                if(memoListM[i][y][x] != list[y][x]){
                     oneResult = false;
                }
            }
        }
        if(oneResult){
            // cout << i << endl;
            return true;
        }   
    }
    return result;

}

int main(){
    cin >> N >> M;
    listS.resize(N, vector<ll>(N));
    for(ll y = 0; y < N; y ++){
        for(ll x = 0; x < N; x ++){
            char c;
            cin >> c;
            if(c == '#'){
                listS[y][x] = 1;
            }else{
                listS[y][x] = 0;
            }
            
        }
    }
    
    for(ll y = 0; y < N - M + 1; y ++){
        for(ll x = 0; x < N - M + 1; x ++){
            vector<vector<ll>> listM;
            listM.resize(M, vector<ll>(M));
            // cout << x << ", " << y << endl;
            for(int y0 = 0; y0 < M; y0 ++){
                for(int x0 = 0; x0 < M; x0 ++){
                    listM[y0][x0] = listS[y + y0][x + x0];
                    // cout << listM[y0][x0];
                }
                // cout << endl;
            }
            // cout << endl;
            if(!inMemo(listM)){
                memoListM.push_back(listM);
            }
            // cout << "nowResult = " << memoListM.size() << endl;
        }
    }
    cout << memoListM.size() << endl;

    
}

