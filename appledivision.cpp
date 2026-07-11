#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;

ll minweight(const vector<ll> &P) {}

int main() {
  int N;
  cin >> N;
  vector<ll> P(N);
  for (int i = 0; i < N; ++i) {
    cin >> P[i];
  }

  cout << minweight(P);
}
