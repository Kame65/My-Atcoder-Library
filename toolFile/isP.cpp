#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

vector<bool> isp;

void sieve() {
    ll largeN = 1e7 + 100;
  isp[0] = false;
  isp[1] = false;
  for (int i=2; pow(i,2)<= largeN; i++) {
    if (isp[i]) for(int j=2; i*j<=largeN; j++) isp[i*j] = false;
  }
}