#include <bits/stdc++.h>
using namespace std;

int kemenangan(vector<int> P) {}

int main(int argc, char *argv[]) {
  int N, D;
  cin >> N >> D;

  vector<int> P(N);
  for (int i = 0; i < N; ++i) {
    cin >> P[i];
  }

  cout << kemenangan(P);
  return 0;
}
