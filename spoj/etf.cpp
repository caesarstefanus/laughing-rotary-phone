#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

int main() {
  bool stat[1000100];
  vector<int> prime; prime.clear();
  for(int i = 2; i < 1000100; ++i) stat[i] = true;
  for(int i = 2; i * i < 1000100; ++i) {
    if(stat[i]) {
      for(int j = 2; i * j < 1000100; ++j) {
        stat[i * j] = false;
      }
    }
  }
  for(int i = 2; i < 1000100; ++i) {
    if(stat[i]) prime.push_back(i);
  }
  int sz = prime.size();
  int t, n;
  scanf("%d", &t);
  for(int i = 0; i < t; ++i) {
    scanf("%d", &n);
    if(stat[n]) printf("%d\n", n - 1);
    else {
      int ans = n;
      for(int i = 0; i < sz; ++i) {
        if(n % prime[i] == 0) {
          ans /= prime[i];
          ans *= prime[i] - 1;
          while(n % prime[i] == 0)
            n /= prime[i];
        }
        if(n == 1) break;
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
