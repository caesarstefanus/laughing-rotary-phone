#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int n;
  while(scanf("%d", &n)) {
    if(n == 0) break;
    int a[100100];
    int b[100100];
    bool stat = true;
    for(int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      b[a[i]] = i;
    }
    for(int i = 1; i <= n; ++i) {
      if(a[i] != b[i]) {
        stat = false;
        break;
      }
    }
    if(stat) printf("ambiguous\n");
    else printf("not ambiguous\n");
  }
  return 0;
}
