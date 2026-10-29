#include<iostream>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    int side[M][2];
    for(int i = 0; i < M; i ++){
        cin >> side[i][0] >> side[i][1];
    }
    //初期化
    int countVertex[N + 1];
    for(int i = 1; i <= N; i ++){
        countVertex[i] = 0;
    }
    for(int i = 0; i < M; i ++){
        countVertex[side[i][0]] ++;
        countVertex[side[i][1]] ++;
    }

    for(int i = 1; i <= N; i ++){
       cout << i << ":" << countVertex[i] << endl;
    }

    int resultCount = 0;

    for(int i = 1; i <= N; i ++){
        while(countVertex[i] > 2){
            int j = 0;
            cout << i << endl;
            for(j = 0; j < M; j ++){
                
                if((side[j][0] == i || side[j][1] == i) && (countVertex[side[j][0]] > 2 && countVertex[side[j][1]] > 2)){
                    cout << side[j][0] << "|" << side[j][1] << endl;
                    countVertex[side[j][0]] -= 1;
                    countVertex[side[j][1]] -= 1;
                    side[j][0] = 0;
                    side[j][1] = 0;
                    resultCount ++;
                    for(int k = 1; k <= N; k ++){
                    cout << k << ":" << countVertex[k] << endl;
                    }
                    break;
                    
                }   
            }
            if(j == M){
                cout << "break";
                break;
            }
                
        }

    }
    //3以上同士のペアなし
    cout << "3以上なし" << endl;
    for(int i = 1; i <= N; i ++){
       cout << i << ":" << countVertex[i] << endl;
    }


    for(int i = 1; i <= N; i ++){
        while(countVertex[i]  > 2){
            // cout << i;
            for(int j = 0; j < M; j ++){
                // cout << j << ":" << side[j][0] << "|" << side[j][1] << endl;
                if(side[j][0] == i || side[j][1] == i){
                    side[j][0] = 0;
                    side[j][1] = 0;
                    countVertex[side[j][0]] -= 1;
                    countVertex[side[j][1]] -= 1;
                    resultCount ++;
                }
            }
        }
    }
    int lessCount = 0;

    for(int i = 1; i <= N; i ++){
        if(countVertex[i] < 2){
            countVertex[i] ++;
            lessCount ++;
        }
    }
    if(lessCount == 1){
        lessCount += 4;
    }
    for(int i = 1; i <= N; i ++){
        if(countVertex[i] < 2){
            countVertex[i] ++;
            lessCount ++;
        }
    }


    cout << "beforeResultCount: " << resultCount << endl;
    cout << "lessCount" << lessCount << endl;
    
    resultCount += (lessCount / 2);

    

    if(resultCount == 0){
        cout << -1 << endl;
    }else{
        cout << resultCount << endl;
    }



}


