#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n, L, R;
    cin >> n >> L >> R;
    vector <char> oxList(n + 1);
    for(int i = 1; i <= n; i ++){
        char c;
        cin >> oxList[i];
    }
    for(int i = L; i <= R; i ++){
        if(oxList[i] != 'o'){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}