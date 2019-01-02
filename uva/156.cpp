//caesar stefanus
//uva 156
//Ananagrams
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

string check(string s) {
  for(int i = 0; i < s.length(); ++i)
    if('A' <= s[i] && s[i] <= 'Z')
      s[i] += 'a' - 'A';
  sort(s.begin(), s.end());
  return s;
}

int main() {
  map<string, int> dick; dick.clear();
  char ch[111];
  vector<string> answer; answer.clear();

  while(scanf("%s", ch)) {
    string s = ch;
    int len = strlen(ch);
    if(s == "#") break;
    if(dick[check(s)] == 0) {
      answer.push_back(s);
    }
    ++dick[check(s)];
  }
  sort(answer.begin(), answer.end());
  int sz = answer.size();
  for(int i = 0; i < sz; ++i) {
    if(dick[check(answer[i])] == 1)
      printf("%s\n", answer[i].c_str());
  }
  return 0;
}
