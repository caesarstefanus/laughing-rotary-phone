#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    long long n;
    scanf("%lld", &n);
    printf("%lld\n", (n * (n + 2) * (2 * n + 1)) / 8);
  }
  return 0;
}
