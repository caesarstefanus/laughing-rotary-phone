#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>

using namespace std;

long long ans = 0;

pair<vector<int>, vector<int> > split(vector<int> a) {
  int sz = a.size();
  int mid = sz / 2;
  vector<int> b; b.clear();
  vector<int> c; c.clear();
  for(int i = 0; i < mid; ++i) b.push_back(a[i]);
  for(int i = mid; i < sz; ++i) c.push_back(a[i]);
  return make_pair(b, c);
}

vector<int> merge(vector<int> b, vector<int> c) {
  vector<int> a; a.clear();
  int pb = 0;
  int pc = 0;
  int szb = b.size();
  int szc = c.size();
  long long cnt = 0;
  while(pb < szb && pc < szc) {
    if(b[pb] < c[pc]) {
      a.push_back(b[pb]);
      ++pb;
    } else {
      a.push_back(c[pc]);
      ++pc;
      cnt += szb - pb;
      //cout << cnt << endl;
    }
  }
  while(pb < szb) {
    a.push_back(b[pb]);
    ++pb;
  }
  while(pc < szc) {
    a.push_back(c[pc]);
    ++pc;
  }
  ans += cnt;
  return a;
}

vector<int> merge_sort(vector<int> a) {
  int sz = a.size();
  if(sz == 1) return a;
  pair<vector<int>, vector<int> > bc = split(a);
  vector<int> b = merge_sort(bc.first);
  vector<int> c = merge_sort(bc.second);
  return merge(b, c);
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);

    vector<int> a; a.clear();
    for(int i = 0, temp; i < n; ++i) {
      scanf("%d", &temp);
      a.push_back(temp);
    }
    vector<int> sorted = merge_sort(a);
    //for(int i = 0; i < n; ++i) cout << sorted[i] << " ";
    //cout << endl;
    //cout << ans << endl;
    printf("%lld\n", ans);
    ans = 0;
  }
  return 0;
}
