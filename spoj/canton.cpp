#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    int row;
    int sum = 0;
    for(int i = 1; i <= n; ++i) {
      //cout << sum << endl;
      sum += i;
      if(sum >= n) {
        row = i;
        break;
      }
    }
    //cout << row << endl;
    if(row % 2 == 0) printf("TERM %d IS %d/%d\n", n, row - sum + n, sum - n + 1);
    else printf("TERM %d IS %d/%d\n", n, sum - n + 1, row - sum + n);
  }
  return 0;
}
