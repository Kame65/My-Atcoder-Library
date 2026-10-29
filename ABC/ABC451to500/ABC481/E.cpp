#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;


struct point {
    ll x, y;
};
long long cross(const point &a, const point &b) {
    return (long long) a.x * b.y - (long long) a.y * b.x;
}
bool cmp(const point &a, const point &b) {
    int ah = (a.y < 0 or (a.y == 0 and a.x < 0));
    int bh = (b.y < 0 or (b.y == 0 and b.x < 0));
    if (ah != bh) return ah < bh;
    return cross(a, b) > 0;
}

void solveCase(){
    ll N;cin >> N;
    vector<point> points(N);
    for(ll i = 0; i < N; i ++){
        cin >> points[i].x >> points[i].y;
        // cout << "i = " << i << endl;
    }
    sort(points.begin(), points.end(), cmp);
    // cout << "sort" << endl;
    // for(int i = 0; i < N; i ++){
    //     cout << points[i].x << " " << points[i].y << "\n";
    // }
    auto copyP = points;
    points.insert(points.end(), copyP.begin(), copyP.end());

    ll l = 0,r = 0, ans = 1;

    while(true){
        // cout << "l, r = " << l << " " << r << endl;
        auto p1 = points[l];
        auto p2 = points[r];
        // cout << "p1: " << p1.x << " " << p1.y << endl;
        // cout << "p2: " << p2.x << " " << p2.y << endl;
        // cout << "cross = " << (ll)p1.x * p2.y - (ll)p1.y * p2.x << endl;
        if(p1.x == p2.x && p1.y == p2.y){
            r ++;
        } else if(p1.x * p2.y - p1.y * p2.x > 0){
            r ++;
        }else{
            l ++;
        }
        ans = max(r - l, ans);
        if(r >= 2 * N)break;
        if(l >= N)break;
    }
    cout << min(ans, N) << endl;
}

int main(){
    ll T; cin >> T;
    for(ll i = 0; i < T; i ++){
        solveCase();
    }
    
}