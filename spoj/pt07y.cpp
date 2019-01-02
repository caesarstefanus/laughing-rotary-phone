#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  bool answer = (m == n - 1) ? true : false;
  if(answer) {
    vector<int> graph[10100];
    bool vis[10100];
    for(int i = 0; i <= n; ++i) {
      vis[i] = false;
      graph[i].clear();
    }
    for(int i = 0, u, v; i < m; ++i) {
      scanf("%d %d", &u, &v);
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    //dfs
    stack<int> si;
    while(!si.empty()) si.pop();
    si.push(1);
    while(!si.empty()) {
      int st = si.top();
      si.pop();
      if(!vis[st]) {
        vis[st] = true;
        int sz = graph[st].size();
        for(int i = 0; i < sz; ++i) {
          si.push(graph[st][i]);
        }
      }
    }
    for(int i = 1; i <= n; ++i) {
      if(!vis[i]) {
        answer = false;
        break;
      }
    }
  }
  if(answer) printf("YES\n");
  else printf("NO\n");
  return 0;
}
