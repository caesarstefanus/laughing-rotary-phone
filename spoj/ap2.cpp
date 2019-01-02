#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    long long x, y, sum;
    scanf("%lld %lld %lld", &x, &y, &sum);
    long long n = sum + sum;
    n /= (x + y);
    long long b = y - x;
    b /= (n - 5);
    long long a = x;
    a -= (b * 2);
    printf("%lld\n", n);
    for(int i = 0; i < n; ++i) {
      if(i > 0) printf(" ");
      printf("%lld", a + (i * b));
    }
    printf("\n");
  }
  return 0;
}
