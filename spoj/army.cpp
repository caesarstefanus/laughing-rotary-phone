#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int a, b;
    vector<int> va, vb;
    va.clear();
    vb.clear();
    scanf("%d %d", &a, &b);
    for(int i = 0, temp; i < a; ++i) {
      scanf("%d", &temp);
      va.push_back(temp);
    }
    for(int i = 0, temp; i < b; ++i) {
      scanf("%d", &temp);
      vb.push_back(temp);
    }
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    int pa = 0;
    int pb = 0;
    while(pa < a && pb < b) {
      //cout << pa << " " << pb;
      if(va[pa] < vb[pb]) {
        ++pa;
      } else {
        ++pb;
      }
    }
    if(pa == a) printf("MechaGodzilla\n");
    else printf("Godzilla\n");
  }
  return 0;
}
