#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main() {

  int t;
  long long k;
  scanf("%d", &t);
  while(t--) {
    scanf("%lld", &k);
    if((k - 1) / 4 > 0) printf("%lld", (k - 1) / 4);
    if(k % 4 == 1) printf("192\n");
    else if(k % 4 == 2) printf("442\n");
    else if(k % 4 == 3) printf("692\n");
    else if(k % 4 == 0) printf("942\n");
  }
  /*
  for(long long i = 1; i < 10000; ++i) {
    long long check = i;
    check *= i;
    check %= 1000;
    check *= i;
    check %= 1000;
    if(check == 888) cout << i << endl;
  }
  */
  return 0;
}
