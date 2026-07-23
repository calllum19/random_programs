#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
  string input;
  cin >> input;
  // To get smallest N * N, perhaps square root
  int N = ceil(sqrt(input.size()));
  int ssize = input.size();
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      int dex;
      if (i % 2 == 0) {
        dex = (i * N) + j;
      } else {
        dex = (i * N) + (N - 1) - j;
      }
      if (dex >= ssize) {
        cout << '.';
      } else {
        cout << input[dex];
      }
    }
    cout << '\n';
  }
  return 0;
}
