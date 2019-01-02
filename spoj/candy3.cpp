#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    long long n;
    scanf("%lld", &n);
    long long sum = 0;
    for(long long i = 0, num; i < n; ++i) {
      scanf("%lld", &num);
      sum += (num % n);
      sum %= n;
    }
    if(sum == 0) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}
