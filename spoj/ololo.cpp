#include <cstdio>

using namespace std;

int main() {
  int n, temp, ans = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%d", &temp);
    ans ^= temp;
  }
  printf("%d\n", ans);
  return 0;
}
