//caesar stefanus
//uva 161
//Traffic Lights
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int check(int cur, int x) {
  if((cur / x) % 2 == 0 && cur % x < x - 5) return 1;
  else return 0;
}


int main() {
  int x, y, z;
  while(scanf("%d %d %d", &x, &y, &z)) {
    if(x == 0 && y == 0 && z == 0) break;
    int green[22222];
    int cnt = 2;
    for(int i = 0; i < 22222; ++i) green[i] = 0;
    for(int i = 0; i < 22222; ++i) {
      green[i] += check(i, x);
      green[i] += check(i, y);
    }
    while(z > 0) {
      ++cnt;
      for(int i = 0; i < 22222; ++i) {
        green[i] += check(i, z);
      }
      scanf("%d", &z);
    }
    int ptr = 0;
    bool stat = false;
    while(green[ptr] == cnt) ++ptr;
    for(int i = ptr; i <= 18000; ++i) {
      if(green[i] == cnt) {
        int h = i / 3600;
        int m = (i - (h * 3600)) / 60;
        int s = i - (h * 3600) - (m * 60);
        printf("%.2d:%.2d:%.2d\n", h, m, s);
        stat = true;
        break;
      }
    }
    if(!stat) printf("Signals fail to synchronise in 5 hours\n");
  }
  return 0;
}
