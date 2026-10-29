#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    long long int v, a, b, c;
    cin >> v >> a >> b >> c;
    vector<long long int> abc = {a, b, c};
    int who;
    int run;
    while(run){
        for(int i = 0; i < 3; i ++){
            v -= abc[i];
            if(v < 0){
                who = i; 
                run = 0;
                break;
            }
        }
    }
    cout << who << endl;
    if(who == 0){
        cout << "F" << endl;
    }else if(who == 1){
        cout << "M" << endl;
    }else{
        cout << "T" << endl;
    }

}