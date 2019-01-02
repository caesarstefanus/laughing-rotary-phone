#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

vector<int> convert(int x) {
  vector<int> answer; answer.clear();
  while(x > 0) {
    answer.push_back(x % 2);
    x /= 2;
  }
  while(answer.size() < 8) answer.push_back(0);
  reverse(answer.begin(), answer.end());
  return answer;
}

int main() {
  int n, money[10];
  vector< pair<int, int> > war; war.clear();

  for(int i = 0; i < 8; ++i) scanf("%d", &money[i]);

  scanf("%d", &n);
  for(int i = 0, j, k; i < n; ++i) {
    scanf("%d %d", &j, &k);
    war.push_back(make_pair(j - 1, k - 1));
  }

  int ans = 0;
  for(int i = 0; i < (1 << 9); ++i) {
    vector<int> bits = convert(i);
    //check war
    bool status = true;
    for(int j = 0; j < n; ++j) {
      if(bits[war[j].first] == 1 && bits[war[j].second] == 1) {
        status = false;
        break;
      }
    }
    //if ok check money
    if(status) {
      int check = 0;
      for(int j = 0; j < 8; ++j) {
        check += bits[j] * money[j];
      }
      if(ans < check) {
        //for(int j = 0; j < 8; ++j) cout << bits[j];
        //cout << endl << check << endl;
        ans = check;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
