//caesar stefanus
//uva 584
//Bowling
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main() {
  char ch;
  int score[22], status[22];
  int frame = 1;
  int roll = 0;
  for(int i = 0; i < 22; ++i) score[i] = status[i] = 0;
  while(scanf("%c", &ch)) {
    if(ch == 'G') break;
    getchar();

    int num = -1;
    if('0' <= ch && ch <= '9') num = ch - '0';
    else {
      num = 10;
      if(ch == '/') status[frame] = 1;
      else status[frame] = 2;
    }

    score[frame] += num;
    ++roll;
    if((roll == 2 || status[frame] == 2) && frame < 10) {
      roll = 0;
      ++frame;
    }
    else if(frame == 10) {
      if(status[frame] == 2) {

      }
      else {
        
      }
    }
  }
  while(scanf("%c", &ch)) {
    if(ch == '\n' || ch == EOF) break;
  }
  return 0;
}
