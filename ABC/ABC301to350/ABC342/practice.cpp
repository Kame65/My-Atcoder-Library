#include <iostream>
using namespace std;

void print(int x, int y){
    cout << x << "," << y << endl;
}

int main(){
    int x = 0, y = 0;
    print(x, y);
    int r = 1;
    int count = 0;
    while(count <= 5){
        x += 1;
        print(x, y);
        for(int i = 0; i < r; i ++){
            y += 1;
            print(x, y);
        }

        for(int i = 0; i < r; i ++){
            x -= 1;
            print(x, y);
        }
        y += 1;
        r += 1;
        print(x, y);
        for(int i = 0;i < r; i ++){
            x += 1;
            print(x, y);
        }
        for(int i = 0; i < r; i ++){
            y -= 1;
            print(x, y);
        }
        r += 1;

        
        count ++;
        
    }
    
    
}
