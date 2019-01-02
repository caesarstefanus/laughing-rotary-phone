//Caesar Stefanus
//uva 893
//y3k

#include <cstdio>
#include <iostream>

using namespace std;

bool leapyear(int year) {
  return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0));
}

int main() {
  int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int leapmonth[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  int p, d, m, y;
  while(scanf("%d %d %d %d", &p, &d, &m, &y)) {
    if(p + d + m + y == 0) break;

    int current = d;
    for(int i = 0; i < m; ++i)
      current += leapyear(y) ? leapmonth[i] : month[i];
    if(leapyear(y) && current + p > 365) {
      //goto 31st december
      while(m < 12) {

      }
    }
  }
  return 0;
}
