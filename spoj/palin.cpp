#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

string add(string s1, string s2) {
  int len1 = s1.length();
  int len2 = s2.length();

  reverse(s1.begin(), s1.end());
  reverse(s2.begin(), s2.end());

  if(len1 > len2) {
    for(int i = len2; i < len1; ++i) s2 += '0';
  } else {
    for(int i = len1; i < len2; ++i) s1 += '0';
  }
  int len = max(len1, len2);
  string ans = "";
  for(int i = 0; i < len; ++i) ans += '0';

  int carry = 0;
  for(int i = 0; i < len; ++i) {
    int result = carry + s1[i] - '0' + s2[i] - '0';
    ans[i] += result % 10;
    carry = result / 10;
  }

  if(carry > 0) ans += carry + '0';

  reverse(ans.begin(), ans.end());
  return ans;
}

bool check(string s) {
  int len = s.length();
  for(int i = 0; i < len; ++i)
    if(s[i] != '9') return false;
  return true;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    char ch[1000100];
    getchar();
    scanf("%s", ch);
    int len = strlen(ch);
    string s = ch;
    if(check(s)) {
      string ns = "1";
      for(int i = 0; i < len - 1; ++i) ns += '0';
      ns += '1';
      printf("%s\n", ns.c_str());
    } else {
      string ns = s.substr(0, (len + 1) / 2);
      string cs = add(ns, "1");

      for(int i = (len / 2) - 1; i >= 0; --i) ns += s[i];

      if(ns <= s) {
        printf("%s", cs.c_str());
        reverse(cs.begin(), cs.end());
        if(len % 2 == 0) printf("%s\n", cs.c_str());
        else printf("%s\n", cs.substr(1).c_str());
      } else printf("%s\n", ns.c_str());
    }
  }
  return 0;
}
