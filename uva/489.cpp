//caesar stefanus
//uva 489
//Hangman Judge
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <map>

using namespace std;

int main() {
  int xxx;
  while(cin >> xxx) {
    if(xxx == -1) break;
    cout << "Round " << xxx << "\n";
    getchar();
    string ans, guess;
    cin >> ans >> guess;
    map<char, bool> stat; stat.clear();
    map<char, bool> guessed; guessed.clear();
    /*
    cout << xxx << endl;
    cout << "xx" << ans << "x\n";
    cout << "xy" << guess << "y\n";
    */
    int lenans = ans.length();
    int lenguess = guess.length();
    int sz = 0;
    int wrong = 0;

    for(int i = 0; i < lenans; ++i) {
      if(!stat[ans[i]]) ++sz;
      stat[ans[i]] = true;
    }
    string newguess = "";
    for(int i = 0; i < lenguess; ++i) {
      if(!guessed[guess[i]]) {
        newguess += guess[i];
        guessed[guess[i]] = true;
      }
    }
    int lennewguess = newguess.length();
    for(int i = 0; i < lennewguess; ++i) {
      if(stat[newguess[i]]) {
        stat[newguess[i]] = false;
        --sz;
      }
      else ++wrong;
      if(wrong >= 7) {
        cout << "You lose.\n";
        break;
      }
      if(sz == 0) {
        cout << "You win.\n";
        break;
      }
    }
    if(wrong < 7 && sz > 0) cout << "You chickened out.\n";
  }
  return 0;
}
