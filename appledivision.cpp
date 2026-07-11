#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;

ll appledivision(const vector<ll> &p) {
  vector<ll> values;
  ll heldvalue1 = 0;
  ll heldvalue2 = 0;
  for (int i = 1; i <= p.size(); ++i) {
    for (int k = 0; k <= i - 1; ++k) {
      heldvalue1 += p[k];
    }
    for (int j = p.size() - 1; j >= i; --j) {
      heldvalue2 += p[j];
    }
    values.push_back(abs(heldvalue1 - heldvalue2));
    heldvalue1 = 0;
    heldvalue2 = 0;
  }
  return *min_element(values.begin(), values.end());
}

int main() {
  int N;
  cin >> N;
  vector<ll> p(N);
  for (int i = 0; i < N; ++i) {
    cin >> p[i];
  }

  cout << appledivision(p);
}
