#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

vector<int> min1(vector<int> m) {
  int len = m.size();
  int pos = len - 1;
  --m[pos];
  while(pos > 0 && m[pos] < 0) {
    m[pos] = 9;
    --pos;
    --m[pos];
  }
  if(m[0] == 0) {
    m.erase(m.begin());
  }
  return m;
}

vector<int> mul2(vector<int> m) {
  int len = m.size();
  reverse(m.begin(), m.end());
  int pos = 0;
  vector<int> ans; ans.clear();
  for(int i = 0; i < len; ++i) {
    ans.push_back(m[i] * 2);
    //cout << ans[i] <<"x\n";
  }
  for(int i = 0; i < len - 1; ++i) {
    if(ans[i] > 9) {
      ans[i] -= 10;
      ++ans[i + 1];
    }
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main() {
  char s[111];
  while(scanf("%s", s) != EOF) {
    vector<int> m; m.clear();
    int len = strlen(s);
    if(len == 1 && s[0] == '1') {
      printf("1\n");
    } else {
      for(int i = 0; i < len; ++i) m.push_back(s[i] - '0');
      m = min1(m);
      m = mul2(m);
      len = m.size();
      for(int i = 0; i < len; ++i) printf("%d", m[i]);
      printf("\n");
    }
  }
  return 0;
}
