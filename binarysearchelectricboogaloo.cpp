#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int belongingto(const vector<int> &cows, const int &cond) {
  return 1 + lower_bound(cows.begin(), cows.end(), cond) - cows.begin();
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;
  vector<int> A(N);
  cin >> A[0];
  for (int i = 1; i < N; ++i) {
    cin >> A[i];
    A[i] += A[i - 1];
  }
  int Q;
  cin >> Q;
  vector<int> X(Q);
  for (int i = 0; i < Q; ++i) {
    cin >> X[i];
  }

  for (int i = 0; i < Q; ++i) {
    cout << belongingto(A, X[i]) << '\n';
  }
  return 0;
}
