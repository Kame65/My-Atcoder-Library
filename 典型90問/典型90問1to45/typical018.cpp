#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numbers>
#include <iomanip>

using namespace std;
using ll = long long int;

vector<double>locY = {0, -0.5, 0, 0.5}, locZ = {0, 0.5, 1, 0.5};
int main(){
    int T;
    long double L, X, Y, Q;
    cin >> T >> L >> X >> Y >> Q;
    for(ll i = 0; i < Q; i ++){
        ll e;
        cin >> e;
        e %= T;
        long double radian = e / double(T) * 2.0 * M_PI;
        long double exX, exY, exZ;
        // cout << "radian = " << radian << endl;
        exX = 0;
        exY = - 0.5 * L * sin(radian);
        exZ = 0.5 * L *(1.0 - cos(radian));
        long double locXY = sqrt((pow(X - exX, 2) + pow(Y - exY, 2)));
        long double locZ = exZ;
        // cout << "place : " << exX << ", " << exY << ", " << exZ << endl;
        cout << fixed << setprecision(15) << atan2(locZ, locXY) * 180.0 / M_PI << endl;
    }
    // cout << L << endl;


}