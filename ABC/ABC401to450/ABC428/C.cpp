#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <stack>

using namespace std;
using ll = long long int;

ll Q;
vector<int> qtype, qchar, memo, st;

int main(){
    cin >> Q;
    qtype.resize(Q);
    qchar.resize(Q);

    for(ll i = 0; i < Q; i ++){
        cin >> qtype[i];
        if(qtype[i] == 1){
            char c;
            cin >> c;
            if(c == '('){
                qchar[i] = 1;
            }else{
                qchar[i] = -1;
            }
        }
    }
    //入力完了
    ll missCount = 0;
    for(int i = 0; i < Q; i ++){
        if(qtype[i] == 1){//(or)
            memo.push_back(qchar[i]);
            if(qchar[i] == 1){
                if(missCount > 0){
                    missCount ++;
                }else{
                    st.push_back(1);
                }
            }else if(st.size() > 0){
                st.pop_back();
            }else{
                missCount ++;
            }
        }else{
            int val = memo.back();
            memo.pop_back();
            if(missCount > 0){
                missCount --;
            }else{
                if(val == 1){//(
                    st.pop_back();
                }else{
                    st.push_back(1);
                }
            }
        }
        if(st.size() == 0 && missCount == 0){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}
