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
  int count = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N - i - 1; ++j) {
      if (A[j] > A[j + 1]) {
        swap(A[j], A[j + 1]);
        ++count;
      }
    }
  }
  /* for (const int &num : A) {
    cout << num << '\n';
  } */
  cout << count;
  return 0;
}
