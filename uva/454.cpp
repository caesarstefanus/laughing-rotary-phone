//caesar stefanus
//uva 454
//Anagrams
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string updated(string s) {
  string sans = "";
  int len = s.length();
  for(int i = 0; i < len; ++i)
    if(s[i] != ' ')
      sans += s[i];
  return sans;
}

int main() {
  int TC;
  scanf("%d", &TC);
  getchar();
  getchar();
  /*
  while(TC--) {
    while(1) {
      char temp = getchar();
      if(temp == '\n' || temp == EOF) {
        cout << "newline\n";
        break;
      }
      string line;
      getline(cin, line);
      cout << temp << "+" << line << endl;
    }
  }
  */

  while(TC--) {
    vector<string> words; words.clear();
    map<string, vector<string> > dick; dick.clear();
    map<string, bool> exist; exist.clear();

    while(1) {
      char temp = getchar();
      if(temp == '\n' || temp == EOF) {
        //cout << "success\n";
        break;
      }

      string smain = "";
      string stemp = "";
      smain += temp;
      getline(cin, stemp);
      smain += stemp;
      //cout << smain << "\n";

      string ssorted = updated(smain);
      sort(ssorted.begin(), ssorted.end());
      dick[ssorted].push_back(smain);
      if(!exist[smain]) {
        exist[smain] = true;
        words.push_back(smain);
      }
    }

    sort(words.begin(), words.end());
    int sz = words.size();
    for(int i = 0; i < sz; ++i) {
      string ssorted = updated(words[i]);
      sort(ssorted.begin(), ssorted.end());
      sort(dick[ssorted].begin(), dick[ssorted].end());
      int sz2 = dick[ssorted].size();

      int same = 0;
      for(int j = 0; j < sz2; ++j) {
        if(words[i] == dick[ssorted][j])
          ++same;
      }
      if(same > 1) {
        for(int j = 0; j < same * (same - 1) / 2; ++j)
          cout << words[i] << " = " << words[i] << "\n";
      }
      for(int j = 0; j < sz2; ++j) {
        if(words[i] < dick[ssorted][j])
          cout << words[i] << " = " << dick[ssorted][j] << "\n";
      }
    }
    if(TC > 0) cout << "\n";
  }

  return 0;
}
