#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  for(int i = 1; i <= t; ++i) {
    long long r;
    scanf("%lld", &r);
    printf("Case %d: %lld.25\n", i, 4 * r * r);
  }
  return 0;
}
