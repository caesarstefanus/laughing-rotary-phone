#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<long long, long long> dp;

long long solve(long long n) {
  if(n < 12) return n;
  if(dp[n] < n) dp[n] = max(n, solve(n/2) + solve(n/3) + solve(n/4));
  return dp[n];
}

int main() {
  long long n;
  while(scanf("%lld", &n) != EOF) {
    printf("%lld\n", solve(n));
  }
  return 0;
}
