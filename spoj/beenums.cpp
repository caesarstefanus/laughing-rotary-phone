#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

int main() {
  map<int, bool> stat; stat.clear();
  for(int i = 0; 3 * i * (i + 1) + 1 <= 1000000000; ++i) {
    int ans = 3 * i * (i + 1) + 1;
    stat[ans] = true;
  }
  int n;
  while(scanf("%d", &n)) {
    if(n == -1) break;
    if(stat[n]) printf("Y\n");
    else printf("N\n");
  }
  return 0;
}
