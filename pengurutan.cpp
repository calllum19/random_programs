#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i)
    cin >> A[i];
  sort(A.begin(), A.end());
  cout << fixed << setprecision(1);
  if ((A.size() - 1) % 2 == 0) {
    cout << (double)A[(A.size() - 1) / 2];
  } else {
    cout << (A[(A.size() - 1) / 2] + A[((A.size() - 1) / 2) + 1]) / 2.0;
  }
  return 0;
}
