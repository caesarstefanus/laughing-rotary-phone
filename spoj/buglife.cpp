#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  for(int tc = 1; tc <= t; ++tc) {
    int noOfBugs, interaction;
    vector<int> graph[2222];
    bool vis[2222];
    int value[2222];

    bool answer = false;
    scanf("%d %d", &noOfBugs, &interaction);
    for(int i = 0; i <= noOfBugs; ++i) {
      graph[i].clear();
      vis[i] = false;
      value[i] = 0;
    }
    for(int i = 0, j, k; i < interaction; ++i) {
      scanf("%d %d", &j, &k);
      graph[j].push_back(k);
      graph[k].push_back(j);
    }

    //bfs
    for(int i = 1; i <= noOfBugs; ++i) {
      if(!vis[i]) {
        value[i] = 1;
        queue<int> qi;
        while(!qi.empty()) qi.pop();
        qi.push(i);
        vis[i] = true;
        while(!qi.empty()) {
          int qf = qi.front();
          qi.pop();
          int sz = graph[qf].size();
          for(int j = 0; j < sz; ++j) {
            if(!vis[graph[qf][j]]) {
              qi.push(graph[qf][j]);
              vis[graph[qf][j]] = true;
              if(value[qf] == 1) value[graph[qf][j]] = 2;
              else if(value[qf] == 2) value[graph[qf][j]] = 1;
            }
          }
        }
      }
    }

    for(int i = 1; i <= noOfBugs; ++i) {
      int sz = graph[i].size();
      for(int j = 0; j < sz; ++j) {
        //cout << i << " " << graph[i][j] << "\n";
        //cout << value[i] << " " << value[graph[i][j]] << "\n";
        if(value[i] == value[graph[i][j]] && value[i] > 0) {
          answer = true;
          break;
        }
      }
      if(answer) break;
    }

    //output
    printf("Scenario #%d:\n", tc);
    if(answer) printf("Suspicious bugs found!\n");
    else printf("No suspicious bugs found!\n");
  }
  return 0;
}
