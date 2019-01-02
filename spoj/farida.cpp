#include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 10100

typedef long long ll;

ll dp[MAXN];
ll m[MAXN];
int n;

ll solve(int pos) {
  if(pos >= n) return 0;
  if(dp[pos] == 0) dp[pos] = max(m[pos] + solve(pos + 2), solve(pos + 1));
  return dp[pos];
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tc = 1; tc <= t; ++tc) {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
      scanf("%lld", &m[i]);
      dp[i] = 0;
    }
    printf("Case %d: %lld\n", tc, solve(0));
  }
  return 0;
}
