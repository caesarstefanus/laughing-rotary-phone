//caesar stefanus
//uva 11459
//Snakes and Ladders
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int TC;
  scanf("%d", &TC);
  while(TC--) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int board[111];
    for(int i = 0; i < 111; ++i) board[i] = 0;
    for(int i = 0; i < b; ++i) {
      int start, finish;
      scanf("%d %d", &start, &finish);
      if(start != 100)
        board[start] = finish;
      //if(finish != 100) board[finish] = start;
    }
    int player[1000100];
    for(int i = 0; i < 1000100; ++i) player[i] = 1;
    int current = 0;
    bool gameover = false;
    for(int i = 0; i < c; ++i) {
      int dice;
      scanf("%d", &dice);
      if(!gameover) {
        player[current] += dice;
        if(player[current] > 100) player[current] = 100;
        if(board[player[current]] > 0) player[current] = board[player[current]];

        if(player[current] == 100) gameover = true;
        //cout << current << " " << player[current] << endl;
        ++current;
        if(a > 0) current %= a;
      }
    }
    for(int i = 0; i < a; ++i)
      printf("Position of player %d is %d.\n", i + 1, player[i]);
  }
  return 0;
}
