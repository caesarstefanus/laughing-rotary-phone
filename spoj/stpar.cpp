#include <cstdio>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
  int n;
  while(scanf("%d", &n)) {
    if(n == 0) break;
    stack<int> parade;
    while(!parade.empty()) parade.pop();

    int current = 1;
    for(int i = 0, num; i < n; ++i) {
      scanf("%d", &num);
      if(num == current) ++current;
      else {
        while(!parade.empty() && parade.top() == current) {
          parade.pop();
          ++current;
        }
        parade.push(num);
      }
    }

    while(!parade.empty() && parade.top() == current) {
      parade.pop();
      ++current;
    }

    //cout << current << endl;
    //if(!parade.empty()) cout << parade.top() << endl;

    if(current == n + 1 && parade.empty()) printf("yes\n");
    else printf("no\n");
  }
  return 0;
}
