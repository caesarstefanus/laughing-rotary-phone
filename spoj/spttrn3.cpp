#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int t, n;
  char ch[111][111];
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    for(int i = 0; i <= (n - 1) / 2; ++i) {
      for(int j = i; j < n - i; ++j) {
        for(int k = i; k < n - i; ++k) {
          ch[j][k] = (i % 2 == 0) ? '*' : '.';
        }
      }
    }

    int x = 0, y = 1;
    while(y <= n / 2) {
      if(ch[y][x] == '*') ch[y][x] = '.';
      else ch[y][x] = '*';
      ++y;
      ++x;
    }

    if(n % 4 == 0) {
      y = n / 2;
      x = y - 1;
      if(ch[y][x] == '*') ch[y][x] = '.';
      else ch[y][x] = '*';
    }

    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        if(((i % 4 == 2 || i % 4 == 3) && i < j && j < n - i) || ((j % 4 == 2 || j % 4 == 3) && j < i && i < n - j)) printf("%c", ch[j][i]);
        else printf("%c", ch[i][j]);
      }
      printf("\n");
    }
    if(t > 0) printf("\n");
  }
  return 0;
}

/*


***
..*
***


*.*****
*.*...*
*.*.*.*
*.*.*.*
*.***.*
*.....*
*******


***
..*
***

*/
