#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<string, long long> dp;

long long solve(string s) {
  if(dp[s] < 1) {
    int len = s.length();
    if(len <= 1) dp[s] = (s == "0") ? 0 : 1;
    else {
      if('0' <= s[0] && s[0] <= '2') {
        if(s[0] == '1') {
          if(s[1] == '0') dp[s] = solve(s.substr(2));
          else dp[s] = solve(s.substr(1)) + solve(s.substr(2));
        } else {
          if(s[0] == '2') {
            if(s[1] == '0') dp[s] = solve(s.substr(2));
            else if('1' <= s[1] && s[1] <= '6') dp[s] = solve(s.substr(1)) + solve(s.substr(2));
            else dp[s] = solve(s.substr(1));
          }
        }
      }
      else dp[s] = solve(s.substr(1));
    }
  }
  return dp[s];
}

int main() {
  char ch[5555];
  while(scanf("%s", ch) != EOF) {
    getchar();
    string s = ch;
    if(s == "0") break;
    printf("%lld\n", solve(s));
  }
  return 0;
}
