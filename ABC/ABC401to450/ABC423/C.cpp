#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include<string>

using namespace std;

int main(){
    long long int N;
    cin >> N;
    vector<vector<long long int >> xy(N, vector<long long int>(3));
    for(long long int i = 0; i < N; i ++){
        long long int x;
        cin >> x;
        xy[i][0] = x;
    }
    for(long long int i = 0; i < N; i ++){
        long long int y;
        cin >> y;
        xy[i][1] = y;
    }

    for(long long int i = 0; i < N; i ++){
        char c;
        cin >> c;
        if(c == 'R'){
            xy[i][2] = 1;
        }else{
            xy[i][2] = -1;
        }
    }
    sort(xy.begin(), xy.end(), [](const vector<int> &alpha,const vector<int> &beta){return alpha[1] < beta[1];});;
    long long int x0, y0, x, y;
    x0 = -1;
    y0 = -1;

    string result = "No"; 
    for(long long int i = 0; i < N; i ++){
        long long int minRightX, minLeftX;
        x = xy[i][0];
        y = xy[i][1];
        if(y0 != y){
            if(y0 != -1 && minRightX < minLeftX){
                result = "Yes";
                break;
            }
            y0 = y;
            minRightX = x;
            minLeftX = x;
        }
        if(xy[i][2] == 1){//right
            
        }else{

            }
        }
    }




