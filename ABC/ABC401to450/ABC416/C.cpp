#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<string> newStrings;

void getAllString(string str, int K, vector<string> sumples){
    if(K > 0){
        for(int i = 0; i < sumples.size(); i ++){
            getAllString(str + sumples[i], K - 1, sumples);
        }
    }else{
        newStrings.push_back(str);
    }
}   

int main(){
    int N, K, X;

    cin >> N >> K >> X;

    vector<string> sumples;
    for(int i = 0; i < N; i ++){
        string sumple;
        cin >> sumple;
        sumples.push_back(sumple);
    }
    string str = "";
    getAllString(str, K, sumples);
    sort(newStrings.begin(), newStrings.end());
    cout << newStrings[X - 1] << endl;
}
