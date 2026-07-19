#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int minselisih(vector<int> &A, const int &X) {
  int mindiff = 2e9;
  for (int &value : A) {
    mindiff = min(mindiff, abs(abs(X) - abs(value)));
  }
  if (X > 0) {
    return mindiff + X;
  } else if (0 > X) {
    return X - mindiff;
  } else {
    return 0;
  }
}

int main(int argc, char *argv[]) {
  int N, X;
  cin >> N >> X;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  cout << minselisih(A, X);
  return 0;
}
