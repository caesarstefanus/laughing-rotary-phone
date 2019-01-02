#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
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

string sub(string s1, string s2) {
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

  int borrow = 0;
  for(int i = 0; i < len; ++i) {
    int result = s1[i] - s2[i] - borrow;
    if(result < 0) {
      borrow = 1;
      result += 10;
    } else {
      borrow = 0;
    }
    ans[i] += result;
  }

  reverse(ans.begin(), ans.end());
  int pos = 0;
  while(ans[pos] == '0' && pos < len - 1) ++pos;

  return ans.substr(pos);
}

string div2(string s) {
  int len = s.length();

  string ans = "";
  for(int i = 0; i < len; ++i) ans += '0';

  int carry = 0;
  for(int i = 0; i < len; ++i) {
    int result = ((s[i] - '0') / 2) + carry;
    if(s[i] % 2 == 1) carry = 5;
    else carry = 0;
    ans[i] += result;
  }

  int pos = 0;
  while(ans[pos] == '0' && pos < len - 1) ++pos;

  return ans.substr(pos);
}

int main() {
  char ch1[111], ch2[111];
  while(scanf("%s", ch1) != EOF) {
    getchar();
    scanf("%s", ch2);
    getchar();

    string s1 = ch1;
    string s2 = ch2;

    printf("%s\n", div2(add(s1, s2)).c_str());
    printf("%s\n", div2(sub(s1, s2)).c_str());
  }
  return 0;
}
