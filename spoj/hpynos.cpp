#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {
  long long n, ans = 0;
  map<long long, bool> vis; vis.clear();
  scanf("%lld", &n);
  while(n > 1) {
    long long temp = 0;
    if(vis[n]) {
      ans = -1;
      break;
    }
    vis[n] = true;
    ++ans;
    while(n > 0) {
      temp += (n % 10) * (n % 10);
      n /= 10;
    }
    //cout << temp << endl;
    n = temp;
  }
  printf("%lld\n", ans);
  return 0;
}
