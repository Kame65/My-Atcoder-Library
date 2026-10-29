#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<long long int> A, B;
    int N;
    cin >> N;
    for (int i = 0; i < N; i ++){
        long long int a;
        cin >> a;
        A.push_back(a);
    }
    for (int i = 0; i < N; i ++){
        long long int b;
        cin >> b;
        B.push_back(b);
    }
    int resultA = 0;
    for(int i = 0; i < N; i ++){
        if(A[i] == B[i]){
            resultA ++;
        }
    }
    int resultB = 0;
    for(int i = 0; i < N; i ++){
        for(int j = 0;j < N; j ++){
            if(A[i] == B[j]){
                resultB ++;
            }
        }

    }
    resultB -= resultA;
    cout << resultA << endl;
    cout << resultB << endl;
}