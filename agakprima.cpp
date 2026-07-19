#include <bits/stdc++.h>
using namespace std;

string agakprima(const int &x) {
  int counter = 2; // 1 and the number itself
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      ++counter;
    }
    if (counter > 3) {
      return "BUKAN";
    }
  }
  if (counter <= 3) {
    return "YA";
  } else {
    return "BUKAN";
  }
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  vector<int> N(T);
  for (int i = 0; i < T; ++i) {
    cin >> N[i];
  }
  for (int i = 0; i < T; ++i) {
    if (i == T - 1) {
      cout << agakprima(N[i]);
      break;
    }
    cout << agakprima(N[i]) << "\n";
  }
  return 0;
}
