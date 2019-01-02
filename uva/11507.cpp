//caesar stefanus
//uva 11507
//Bender B. Rodriguez Problem

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <map>

using namespace std;

int main() {
  int l;
  while(scanf("%d", &l)) {
    if(l == 0) break;

    string ans = "+x";
    for(int i = l - 1; i > 0; --i) {
      char ch[3];
      getchar();
      scanf("%s", ch);
      string s = ch;
      //printf("x%sx\n", s);
      if(s != "No") {
        if(ans == "+x") ans = s;
        else {
          if(ans == "-x") {
            ans = s;
            if(ans[0] == '+') ans[0] = '-';
            else ans[0] = '+';
          }
          else {
            if(ans[1] == 'y') {
              if(ans[0] == '+') {
                if(s == "+y") ans = "-x";
                if(s == "-y") ans = "+x";
              }
              else {
                if(s == "+y") ans = "+x";
                if(s == "-y") ans = "-x";
              }
            }
            else {
              if(ans[0] == '+') {
                if(s == "+z") ans = "-x";
                if(s == "-z") ans = "+x";
              }
              else {
                if(s == "+z") ans = "+x";
                if(s == "-z") ans = "-x";
              }
            }
          }
        }
      }
    }
    printf("%s\n", ans.c_str());
  }
  return 0;
}
