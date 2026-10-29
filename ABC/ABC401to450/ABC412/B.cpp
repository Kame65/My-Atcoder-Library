#include<iostream>

using namespace std;

int main(){
    string S;
    string T;
    cin >> S >> T;


    for(int i = 1; i < S.size(); i ++){
        if(isupper(S[i])){
            for(int j = 0; j < T.size(); j ++){
                if(S[i - 1] == T[j]){

                    break;
                }else if(j == T.size() - 1){
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;

}