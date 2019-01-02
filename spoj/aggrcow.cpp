#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, c;
    scanf("%d %d", &n, &c);
    long long stalls[100100];
    for(int i = 0; i < n; ++i) {
      scanf("%lld", &stalls[i]);
    }
    long long dist1[100100];
    sort(stalls, stalls + n);
    long long right = stalls[n - 1] - stalls[0];
    long long left = right;
    for(int i = 1; i < n; ++i) {
      left = min(left, stalls[i] - stalls[i - 1]);
      if(i > 1) dist1[i] = stalls[i] - stalls[1];
    }
    long long ans = 0;
    while(left < right) {
      //cout << left << " " << right << endl;
      long long mid = (left + right) / 2;
      int pos = 0;
      int cow = 1;
      while(pos < n) {
        int npos = pos + 1;
        for(int i = npos; i < n; ++i) {
          if(stalls[i] - stalls[pos] >= mid) {
            pos = i;
            ++cow;
            break;
          }
        }
        if(npos == pos + 1) break;
      }
      if(cow >= c) {
        left = mid + 1;
        ans = mid;
      }
      else {
        if(cow < c) right = mid;
        else {

        }
      }
    }
    //ans = left;
    printf("%lld\n", ans);
  }
  return 0;
}
