#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  getchar();
  while(t--) {
    getchar();
    string s;
    getline(cin, s);
    int len = s.length();
    int m = -1;
    int a = -1;
    int plus = -1;
    int equal = -1;
    for(int i = 0; i < len; ++i) {
      if(s[i] == 'm') m = i;
      if(s[i] == 'a') a = i;
      if(s[i] == '+') plus = i;
      if(s[i] == '=') equal = i;
    }

    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    if(a < plus) {
      //machula in first number
      for(int i = plus + 2; i < equal - 1; ++i) {
        num2 *= 10;
        num2 += s[i] - '0';
      }
      for(int i = equal + 2; i < len; ++i) {
        num3 *= 10;
        num3 += s[i] - '0';
      }
      num1 = num3 - num2;
    } else if(a < equal) {
      //machula in second number
      for(int i = 0; i < plus - 1; ++i) {
        num1 *= 10;
        num1 += s[i] - '0';
      }
      for(int i = equal + 2; i < len; ++i) {
        num3 *= 10;
        num3 += s[i] - '0';
      }
      num2 = num3 - num1;
    } else {
      //machula in third number
      for(int i = 0; i < plus - 1; ++i) {
        num1 *= 10;
        num1 += s[i] - '0';
      }
      for(int i = plus + 2; i < equal - 1; ++i) {
        num2 *= 10;
        num2 += s[i] - '0';
      }
      num3 = num1 + num2;
    }
    printf("%d + %d = %d\n", num1, num2, num3);
  }
  return 0;
}
