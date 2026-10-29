#include<iostream>
using namespace std;

int main(){
  int N;
  string T;
  string A;
  cin >> N;
  for(int i = 0; i < N; i ++){
    cin >> T[i];
  }
  for(int i = 0; i < N; i ++){
    cin >> A[i];
  }
  
  for(int i = 0; i < N; i ++){
    if(T[i] == A[i]){
        cout << "Yes" << endl;
        return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}