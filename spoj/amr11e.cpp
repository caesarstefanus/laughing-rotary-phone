#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  //pre-compute prime less than 5842 / 6
  //using sieve >.<
  bool stat[1000];
  for(int i = 0; i < 1000; ++i) stat[i] = true;
  stat[0] = false;
  stat[1] = false;
  for(int i = 2; i < 34; ++i) {
    for(int j = 2; i * j <= 1000; ++j) {
      stat[i * j] = false;
    }
  }
  vector<int> prime; prime.clear();
  for(int i = 2; i < 1000; ++i) {
    if(stat[i]) {
      prime.push_back(i);
    }
  }
  int primeSize = prime.size();
  vector<int> answer; answer.clear();
  for(int i = 30; i <= 5842; ++i) {
    int cnt = 0;
    for(int j = 0; j < primeSize; ++j) {
      if(i % prime[j] == 0) ++cnt;
      if(cnt >= 3) {
        answer.push_back(i);
        break;
      }
    }
  }
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    printf("%d\n", answer[n - 1]);
  }
  return 0;
}
