#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> node[10100];
  bool vis1[10100];
  bool vis2[10100];
  int dist1[10100];
  int dist2[10100];
  for(int i = 0; i <= n; ++i) {
    node[i].clear();
    vis1[i] = false;
    vis2[i] = false;
    dist1[i] = 0;
    dist2[i] = 0;
  }
  for(int i = 0; i < n - 1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    node[u].push_back(v);
    node[v].push_back(u);
  }
  int maxdist1 = 0;
  int maxnode1 = 0;
  queue<int> qi;
  while(!qi.empty()) qi.pop();
  qi.push(1);
  vis1[1] = true;
  while(!qi.empty()) {
    int qf = qi.front();
    qi.pop();
    if(maxdist1 < dist1[qf]) {
      maxdist1 = dist1[qf];
      maxnode1 = qf;
    }
    int sz = node[qf].size();
    for(int i = 0; i < sz; ++i) {
      if(!vis1[node[qf][i]]) {
        vis1[node[qf][i]] = true;
        dist1[node[qf][i]] = dist1[qf] + 1;
        qi.push(node[qf][i]);
      }
    }
  }

  int maxdist2 = 0;
  int maxnode2 = 0;
  qi.push(maxnode1);
  vis2[maxnode1] = true;
  while(!qi.empty()) {
    int qf = qi.front();
    qi.pop();
    if(maxdist2 < dist2[qf]) {
      maxdist2 = dist2[qf];
      maxnode2 = qf;
    }
    int sz = node[qf].size();
    for(int i = 0; i < sz; ++i) {
      if(!vis2[node[qf][i]]) {
        vis2[node[qf][i]] = true;
        dist2[node[qf][i]] = dist2[qf] + 1;
        qi.push(node[qf][i]);
      }
    }
  }

  printf("%d\n", maxdist2);
  return 0;
}
