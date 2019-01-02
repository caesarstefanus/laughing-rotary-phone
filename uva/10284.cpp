/*
caesar stefanus
uva 10284
Chessboard in FEN
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;


const int dy[] = {1, 0, -1, -1, -1, 0, 1, 1};
const int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int kdy[] = {2, 1, -1, -2, -2, -1, 1, 2};
const int kdx[] = {-1, -2, -2, -1, 1, 2, 2, 1};

bool legal(int y, int x) {
  return (0 <= y && y < 8 && 0 <= x && x < 8);
}

int main() {
  char s[111];
  while(scanf("%s", s) != EOF) {
    //cout << s << endl;
    int len = strlen(s);
    int row = 0;
    int col = 0;
    char board[11][11];
    for(int i = 0; i < 11; ++i)
      for(int j = 0; j < 11; ++j)
        board[i][j] = '-';

    for(int i = 0; i < len; ++i) {
      if('0' <= s[i] && s[i] <= '9') {
        int num = s[i] - '0';
        /*
        for(int j = col; j < col + num; ++j) {
          board[row][col] = ' ';
        }
        */
        col += num;
      }
      else {
        if(s[i] == '/') {
          ++row;
          col = 0;
        }
        else {
          board[row][col++] = s[i];
        }
      }
    }
    /*
    for(int i = 0; i < 8; ++i) {
      for(int j = 0; j < 8; ++j) {
        cout << board[i][j];
      }
      cout << "\n";
    }
    cout << "\n";
    */
    bool attacked[11][11];
    for(int i = 0; i < 11; ++i) {
      for(int j = 0; j < 11; ++j) {
        attacked[i][j] = false;
      }
    }
    for(int i = 0; i < 8; ++i) {
      for(int j = 0; j < 8; ++j) {
        switch(board[i][j]) {
          case 'k':
          for(int k = 0; k < 8; ++k) {
            int ny = i + dy[k];
            int nx = j + dx[k];
            if(legal(ny, nx) && (board[ny][nx] == '-' || ('A' <= board[ny][nx] && board[ny][nx] <= 'Z'))) {
              attacked[ny][nx] = true;
            }
          }
          break;
          case 'q':
          for(int k = 0; k < 8; ++k) {
            int ny = i + dy[k];
            int nx = j + dx[k];
            while(legal(ny, nx) && (board[ny][nx] == '-' || ('A' <= board[ny][nx] && board[ny][nx] <= 'Z'))) {
              attacked[ny][nx] = true;
              if('A' <= board[ny][nx] && board[ny][nx] <= 'Z') break;
              ny += dy[k];
              nx += dx[k];
            }
          }
          break;
          case 'r':
          for(int k = 1; k < 8; k += 2) {
            int ny = i + dy[k];
            int nx = j + dx[k];
            while(legal(ny, nx) && (board[ny][nx] == '-' || ('A' <= board[ny][nx] && board[ny][nx] <= 'Z'))) {
              attacked[ny][nx] = true;
              if('A' <= board[ny][nx] && board[ny][nx] <= 'Z') break;
              ny += dy[k];
              nx += dx[k];
            }
          }
          break;
          case 'b':
          for(int k = 0; k < 8; k += 2) {
            int ny = i + dy[k];
            int nx = j + dx[k];
            while(legal(ny, nx) && (board[ny][nx] == '-' || ('A' <= board[ny][nx] && board[ny][nx] <= 'Z'))) {
              attacked[ny][nx] = true;
              if('A' <= board[ny][nx] && board[ny][nx] <= 'Z') break;
              ny += dy[k];
              nx += dx[k];
            }
          }
          break;
          case 'n':
          for(int k = 0; k < 8; ++k) {
            int ny = i + kdy[k];
            int nx = j + kdx[k];
            if(legal(ny, nx) && (board[ny][nx] == '-' || ('A' <= board[ny][nx] && board[ny][nx] <= 'Z'))) {
              attacked[ny][nx] = true;
            }
          }
          break;
          case 'p':
          if(legal(i + 1, j) && board[i + 1][j] == '-') {
            //attacked[i + 1][j] = true;
          }
          if(legal(i + 1, j - 1) && 'a' <= board[i + 1][j - 1] && board[i + 1][j - 1] <= 'z') {
            attacked[i + 1][j - 1] = true;
          }
          if(legal(i + 1, j - 1) && board[i + 1][j - 1] == '-') {
            attacked[i + 1][j - 1] = true;
          }
          if(legal(i + 1, j + 1) && 'a' <= board[i + 1][j + 1] && board[i + 1][j + 1] <= 'z') {
            attacked[i + 1][j + 1] = true;
          }
          if(legal(i + 1, j + 1) && board[i + 1][j + 1] == '-') {
            attacked[i + 1][j + 1] = true;
          }
          break;
          //white piece
          case 'K':
          for(int k = 0; k < 8; ++k) {
            int ny = i + dy[k];
            int nx = j + dx[k];
            if(legal(ny, nx) && (board[ny][nx] == '-' || ('a' <= board[ny][nx] && board[ny][nx] <= 'z'))) {
              attacked[ny][nx] = true;
            }
          }
          break;
          case 'Q':
          for(int k = 0; k < 8; ++k) {
            int ny = i + dy[k];
            int nx = j + dx[k];
            while(legal(ny, nx) && (board[ny][nx] == '-' || ('a' <= board[ny][nx] && board[ny][nx] <= 'z'))) {
              attacked[ny][nx] = true;
              if('a' <= board[ny][nx] && board[ny][nx] <= 'z') break;
              ny += dy[k];
              nx += dx[k];
            }
          }
          break;
          case 'R':
          for(int k = 1; k < 8; k += 2) {
            int ny = i + dy[k];
            int nx = j + dx[k];
            while(legal(ny, nx) && (board[ny][nx] == '-' || ('a' <= board[ny][nx] && board[ny][nx] <= 'z'))) {
              attacked[ny][nx] = true;
              if('a' <= board[ny][nx] && board[ny][nx] <= 'z') break;
              ny += dy[k];
              nx += dx[k];
            }
          }
          break;
          case 'B':
          for(int k = 0; k < 8; k += 2) {
            int ny = i + dy[k];
            int nx = j + dx[k];
            while(legal(ny, nx) && (board[ny][nx] == '-' || ('a' <= board[ny][nx] && board[ny][nx] <= 'z'))) {
              attacked[ny][nx] = true;
              if('a' <= board[ny][nx] && board[ny][nx] <= 'z') break;
              ny += dy[k];
              nx += dx[k];
            }
          }
          break;
          case 'N':
          for(int k = 0; k < 8; ++k) {
            int ny = i + kdy[k];
            int nx = j + kdx[k];
            if(legal(ny, nx) && (board[ny][nx] == '-' || ('a' <= board[ny][nx] && board[ny][nx] <= 'z'))) {
              attacked[ny][nx] = true;
            }
          }
          break;
          case 'P':
          if(legal(i - 1, j) && board[i - 1][j] == '-') {
            //attacked[i - 1][j] = true;
          }
          if(legal(i - 1, j - 1) && 'A' <= board[i - 1][j - 1] && board[i - 1][j - 1] <= 'Z') {
            attacked[i - 1][j - 1] = true;
          }
          if(legal(i - 1, j - 1) && board[i - 1][j - 1] == '-') {
            attacked[i - 1][j - 1] = true;
          }
          if(legal(i - 1, j + 1) && 'A' <= board[i - 1][j + 1] && board[i - 1][j + 1] <= 'Z') {
            attacked[i - 1][j + 1] = true;
          }
          if(legal(i - 1, j + 1) && board[i - 1][j + 1] == '-') {
            attacked[i - 1][j + 1] = true;
          }
          break;
        }
      }
    }
    int ans = 0;
    for(int i = 0; i < 8; ++i) {
      for(int j = 0; j < 8; ++j) {
        /*
        if(board[i][j] == '-' && !attacked[i][j]) {
          //cout << i << " " << j << " = " << board[i][j] << "\n";
          cout << '*';
        } else {
          cout << board[i][j];
        }
        */
        if(board[i][j] == '-' && !attacked[i][j]) ++ans;
      }
      //cout << "\n";
    }
    printf("%d\n", ans);
  }
  return 0;
}
