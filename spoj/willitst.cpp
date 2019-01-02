#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  /*
  for(int i = 0; i < 100; ++i) {
    int n = i;
    bool cycle = false;
    while(n > 1) {
      if(n % 2 == 0) n /= 2;
      else n = (3*n) + 3;
      if(n == i || n == 3) {
        cycle = true;
        break;
      }
    }
    cout << i;
    if(cycle) cout << "does not stop\n";
    else printf("stop\n");
  }
  */
  long long n;
  scanf("%lld", &n);
  if(n & (n - 1)) printf("NIE\n");
  else printf("TAK\n");
  return 0;
}
