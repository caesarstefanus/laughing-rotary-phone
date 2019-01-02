#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int g, b;
  while(scanf("%d %d", &g, &b)) {
    if(g == -1 && b == -1) break;
    if(g < b) swap(g, b);
    int ans = 0;
    //if(g == b) ans = 1;
    //else {
      ans = g / (b + 1);
      if(g % (b + 1) > 0) ++ans;
    //}
    printf("%d\n", ans);
  }
  return 0;
}
