#include<iostream>

using namespace std;

int main(){
    int n;


    cin >> n;

    int a[n];
    int b[n];
    for(int i = 0; i < n; i ++){
        cin >> a[i] >> b[i];
    }
    int c = 0;
    for(int i = 0; i < n; i ++){
        if(a[i] < b[i]){
            c += 1;
        }
    }
    cout << c << endl;
}