#include <iostream>
#include <vector>
#include <string>


using namespace std;

int main(){
    int n;
    cin >> n;
    vector<char> str(n);
    
    for(int i = 0;i < n; i ++){
        char c;
        cin >> c;
        str[i] = c;
    }


    int q;
    cin >> q;
    char strList[] = {'a', 'b', 'c', 'd', 'e', 'f' ,'g', 'h' ,'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char resultStrList[] = {'a', 'b', 'c', 'd', 'e', 'f' ,'g', 'h' ,'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    
    for(int i = 0; i < q; i ++){
        char before;
        char after;
        cin >> before >> after;
        for(int j= 0; j < sizeof(resultStrList); j ++){
            if(before == resultStrList[j]){
                resultStrList[j] = after;
            }
        }
    }

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < sizeof(strList); j ++){
            if(str[i] == strList[j]){
                str[i] = resultStrList[j];
                break;
            }
        }
    }

    for(int i = 0; i < n; i ++){
        cout << str[i];
    }
    cout << endl;


}