#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>


using namespace std;
using ll = long long int;

ll Q;

priority_queue<int, std::vector<int>, std::greater<int>> min_pq;

int main(){
    cin >> Q;
    for(ll i = 0; i < Q; i ++){
        int type, h;
        cin >> type >> h;
        if(type == 1){
            min_pq.push(h);
        }else{
            while(min_pq.size() > 0 && min_pq.top() <= h){
                min_pq.pop();
                // cout << "size = " << min_pq.size() << endl;
            }

            
        }
        cout << min_pq.size() << endl;
    }
}