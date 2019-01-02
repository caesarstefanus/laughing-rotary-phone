#include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#include <utility>

using namespace std;

#define MAXN 500500
#define mp make_pair
#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> llpll;

vector<ll> suf;

//1-indexed segment tree, apparently...
class SegmentTree {
private: vector<ll> sum, lsum, rsum, a;
  int n;
  int left(int p) {return p << 1;}
  int right(int p) {return 1 + (p << 1);}

  void build(int p, int l, int r) {
    if(l == r) sum[p] = lsum[p] = rsum[p] = a[l];
    else {
      build(left(p), l, (l + r) / 2);
      build(right(p), (l + r) / 2 + 1, r);
      lsum[p] = max(lsum[left(p)], suf[(l + r) / 2] - suf[l - 1] + lsum[right(p)]);
      rsum[p] = max(rsum[right(p)], suf[r] - suf[(l + r) / 2] + rsum[left(p)]);
      sum[p] = max(max(sum[left(p)], sum[right(p)]), rsum[left(p)] + lsum[right(p)]);
    }
    //cout << p << " " << sum[p] << endl;
  }

  llpll maxrsq(int p, int l, int r, int i, int j) {
    //cout << p << l << r << i << j << endl;

    if(i > r || j < l) return mp(0, mp(0, 0)); //outside range
    if(l == i && r == j) return mp(sum[p], mp(lsum[p], rsum[p]));
    if(j <= (l + r) / 2) return maxrsq(left(p), l, (l + r) / 2, i, j);
    if(i > (l + r) / 2) return maxrsq(right(p), (l + r) / 2 + 1, r, i, j);
    llpll p1 = maxrsq(left(p), l, (l + r) / 2, i, (l + r) / 2);
    llpll p2 = maxrsq(right(p), (l + r) / 2 + 1, r, (l + r) / 2 + 1, j);
    ll ret1 = max(p1.st, max(p2.st, p1.nd.nd + p2.nd.st));
    ll ret2 = max(p1.nd.st, suf[(l + r) / 2] - suf[i - 1] + p2.nd.st);
    ll ret3 = max(p2.nd.nd, suf[r] - suf[(l + r) / 2] + p1.nd.nd);
    return mp(ret1, mp(ret2, ret3));
  }

public:
  SegmentTree(const vector<ll> &tempa) {
    a = tempa;
    n = a.size();
    sum.assign(8 * n, 0);
    lsum.assign(8 * n, 0);
    rsum.assign(8 * n, 0);
    build(1, 0, n - 1);
  }
  ll maxrsq(int i, int j) {return maxrsq(1, 0, n - 1, i, j).st;}
};

int main() {
  int n, m;
  scanf("%d", &n);
  vector<ll> list;
  list.clear();
  for(int i = 0; i < n; ++i) {
    ll temp;
    scanf("%lld", &temp);
    list.pb(temp);
    suf.pb(temp);
    if(i > 0) suf[i] += suf[i - 1];
  }
  SegmentTree st(list);
  //cout << "success\n";
  scanf("%d", &m);
  for(int i = 0, l, r; i < m; ++i) {
    scanf("%d %d", &l, &r);
    printf("%lld\n", st.maxrsq(l - 1, r - 1));
  }
  return 0;
}
