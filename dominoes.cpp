#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int argc, char *argv[]) {
  ll N, M;
  cin >> N >> M;

  if (M == 1) {
    cout << N - 1;
  } else {
    cout << N * --M;
  }
  return 0;
}
