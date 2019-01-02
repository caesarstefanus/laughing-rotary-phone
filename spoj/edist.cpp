#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    char a[2222];
    char b[2222];
    scanf("%s", a);
    scanf("%s", b);
    string sa = a;
    string sb = b;
    //cout << sa << sb << endl;
    int lena = sa.length();
    int lenb = sb.length();
    map<int, int> dist[2222];
    for(int i = 0; i <= lena; ++i) {
      for(int j = 0; j <= lenb; ++j) {
        dist[i][j] = 0;
      }
    }
    //distance of any 1st string to an empty 2nd string
    for(int i = 1; i <= lena; ++i) {
      dist[i][0] = i;
    }
    //distance of any 2nd string to an empty 1st string
    for(int i = 1; i <= lenb; ++i) {
      dist[0][i] = i;
    }
    //bottom up dp
    for(int i = 1; i <= lena; ++i) {
      for(int j = 1; j <= lenb; ++j) {
        if(a[i - 1] == b[j - 1]) dist[i][j] = dist[i - 1][j - 1];
        else {
          dist[i][j] = 1 + min(dist[i - 1][j - 1], min(dist[i - 1][j], dist[i][j - 1]));
        }
      }
    }
    /*
    for(int i = 0; i <= lena; ++i) {
      for(int j = 0; j <= lenb; ++j) {
        printf("%d ", dist[i][j]);
      }
      printf("\n");
    }
    */
    printf("%d\n", dist[lena][lenb]);
  }
  return 0;
}
