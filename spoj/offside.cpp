#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int atk, def;
  int a[10100];
  int d[10100];
  while(scanf("%d %d", &atk, &def)) {
    if(atk == 0 && def == 0) break;
    for(int i = 0; i < atk; ++i) {
      scanf("%d", &a[i]);
    }
    for(int i = 0; i < def; ++i) {
      scanf("%d", &d[i]);
    }
    sort(a, a + atk);
    sort(d, d + def);
    if(a[0] >= d[1] || (a[0] >= d[0] && a[0] >= d[1])) printf("N\n");
    else printf("Y\n");
  }
  return 0;
}
