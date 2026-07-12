#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;

ll appledivision(ll index, ll csum, ll totalweight, const vector<ll> &p) {
  if (index == p.size()) {
    return abs(2 * csum - totalweight);
  } else {
    ll exc = appledivision(index + 1, csum, totalweight, p);
    ll inc = appledivision(index + 1, csum + p[index], totalweight, p);
    return min(exc, inc);
  }
}

int main() {
  int N;
  cin >> N;
  vector<ll> p(N);
  ll totalweight = 0;
  for (int i = 0; i < N; ++i) {
    cin >> p[i];
    totalweight += p[i];
  }

  cout << appledivision(0, 0, totalweight, p);
}
