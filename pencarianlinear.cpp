#include <bits/stdc++.h>
using namespace std;

int minselisih(vector<int> &A, const int &X) {
  int currentDiff, bestDiff, bestVal;
  bestDiff = 2e9;
  for (int i = 0; i < A.size(); ++i) {
    currentDiff = abs(A[i] - X);
    if (currentDiff < bestDiff) {
      bestDiff = currentDiff;
      bestVal = A[i];
    } else if (currentDiff == bestDiff) {
      if (A[i] < bestVal)
        bestVal = A[i];
    }
  }
  return bestVal;
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
