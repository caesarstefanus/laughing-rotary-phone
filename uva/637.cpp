//caesar stefanus
//uva 637
//Booklet Printing
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int n;
  while(scanf("%d", &n)) {
    if(n == 0) break;
    int sheet = (n + 3) / 4;
    int sum = (sheet * 4) + 1;
    int y = 1;
    int x = sum - y;
    int cur = 1;
    printf("Printing order for %d pages:\n", n);
    while(x > y && n >= y) {
      if(x > n) {
        if(y % 2 == 1) printf("Sheet %d, front: Blank, %d\n", cur, y);
        else printf("Sheet %d, back : %d, Blank\n", cur++, y);
      }
      else {
        if(y % 2 == 1) printf("Sheet %d, front: %d, %d\n", cur, x, y);
        else printf("Sheet %d, back : %d, %d\n", cur++, y, x);
      }
      --x; ++y;
    }
  }
  return 0;
}
