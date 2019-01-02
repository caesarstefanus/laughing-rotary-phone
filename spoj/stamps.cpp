#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  for(int tc = 1; tc <= t; ++tc) {
    int s, f;
    int stamps[1111];
    int total = 0;
    scanf("%d %d", &s, &f);
    for(int i = 0; i < f; ++i) {
      scanf("%d", &stamps[i]);
      total += stamps[i];
    }
    printf("Scenario #%d:\n", tc);
    if(total < s) printf("impossible\n");
    else {
      sort(stamps, stamps + f);
      reverse(stamps, stamps + f);

      int check = 0;
      int ans = 0;
      for(int i = 0; i < f; ++i) {
        check += stamps[i];
        if(check >= s) {
          ans = i + 1;
          break;
        }
      }
      printf("%d\n\n", ans);
    }
  }
  return 0;
}
