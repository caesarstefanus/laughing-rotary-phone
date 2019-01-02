//caesar stefanus
//uva 11221
//Magic square palindromes.

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

int main() {
  int T;
  cin >> T;
  getchar();
  for(int tc = 1; tc <= T; ++tc) {
    string smain;
    getline(cin, smain);
    //cout << smain << endl;
    string s = "";
    int mainlen = smain.length();
    for(int i = 0; i < mainlen; ++i) {
      if('a' <= smain[i] && smain[i] <= 'z')
        s += smain[i];
    }
    int len = s.length();
    bool palindrome = true;
    for(int i = 0; i < len; ++i) {
      if(s[i] != s[len - i - 1]) {
        palindrome = false;
        break;
      }
    }
    cout << "Case #" << tc << ":\n";
    int temp = sqrt(len);
    if(palindrome && temp * temp == len) cout << temp << "\n";
    else cout << "No magic :(\n";
  }
  return 0;
}
