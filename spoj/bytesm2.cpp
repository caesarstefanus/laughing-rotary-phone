#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int h, w;
    int m[111][111];
    int dp[111][111];
    scanf("%d %d", &h, &w);
    for(int i = 0; i < h; ++i) {
      for(int j = 0; j < w; ++j) {
        scanf("%d", &m[i][j]);
        dp[i][j] = 0;
      }
    }
    for(int i = 0; i < w; ++i) {
      dp[0][i] = m[0][i];
    }
    for(int i = 1; i < h; ++i) {
      dp[i][0] = m[i][0] + max(dp[i - 1][0], dp[i - 1][1]);
      for(int j = 1; j < w - 1; ++j) {
        dp[i][j] = m[i][j] + max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i - 1][j + 1]));
      }
      dp[i][w - 1] = m[i][w - 1] + max(dp[i - 1][w - 1], dp[i - 1][w - 2]);
    }
    /*
    for(int i = 0; i < h; ++i) {
      for(int j = 0; j < w; ++j) {
        printf("%d ", dp[i][j]);
      }
      printf("\n");
    }
    */
    int ans = 0;
    for(int i = 0; i < w; ++i) {
      ans = max(ans, dp[h - 1][i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
