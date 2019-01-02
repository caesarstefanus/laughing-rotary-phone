#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#define INF 1e9
#define MAXN 6666
#define mp make_pair
#define pb push_back
#define st first
#define nd second

typedef pair<int, int> ii;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    char ch[MAXN];
    scanf("%s", ch);
    string s = ch;
    string revs = s;
    reverse(revs.begin(), revs.end());
    int dp[MAXN][MAXN];
    int len = s.length();
    for(int i = 0; i <= len; ++i) {
      for(int j = 0; j <= len; ++j) {
        dp[i][j] = 0;
      }
    }
    //bottom up lcs with dp
    for(int i = 1; i <= len; ++i) {
      for(int j = 1; j <= len; ++j) {
        int pos1 = i - 1;
        int pos2 = j - 1;
        if(s[pos1] == revs[pos2]) dp[i][j] = 1 + dp[i - 1][j - 1];
        else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
    //cout << "hoho\n";
    printf("%d\n", len - dp[len][len]);
    //cout << "hihi\n";
  }
  return 0;
}
