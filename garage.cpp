#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(int argc, char *argv[]) {
  ll N;
  cin >> N;
  if (N == 1)
    cout << 3;
  else if (N > 1) {
    N -= 2;
    ll fullcycle = N / 3;
    ll bonus;
    ll remainder = N % 3;
    if (remainder == 0)
      bonus = 0;
    else if (remainder == 1)
      bonus = 2;
    else if (remainder == 2)
      bonus = 3;

    cout << 5 + (fullcycle * 4) + bonus;
  }
  return 0;
}
