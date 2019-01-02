#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
  {
    long long x;
    scanf("%lld", &x);
    long long ans = x * (3 * x + 1) / 2;
    ans %= 1000007;
    printf("%lld\n", ans);
  }
  return 0;
}
