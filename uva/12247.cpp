//caesar stefanus
//uva 12247
//Jollo
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int a[5], b[5];
  while(scanf("%d %d %d %d %d",&a[0], &a[1], &a[2], &b[0], &b[1])) {
    if(a[0] == 0) break;
    sort(a, a + 3);
    int ans = -1;
    for(int i = 1; i <= 52; ++i) {
      if(i == a[0] || i == a[1] || i == a[2]) continue;
      int c[5];
      c[0] = b[0];
      c[1] = b[1];
      c[2] = i;
      sort(c, c + 3);
      int check1 = 0;
      do {
        int check2 = 0;
        for(int j = 0; j < 3; ++j) {
          if(c[j] > a[j]) ++check2;
        }
        if(check2 >= 2) ++check1;
      } while(next_permutation(c, c + 3));
      if(check1 == 6) {
        ans = i;
        break;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
