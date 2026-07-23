#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  int N;
  cin >> N;
  string p1, p2, p3;
  cin >> p1 >> p2 >> p3;
  // im thinking, maybe to check if letter existed already
  // look up map in reference
  map<char, char> ori2enc;
  map<char, char> enc2ori;
  for (int i = 0; i < N; ++i) {
    char ori = p1[i], enc = p2[i];
    if (ori2enc.count(ori) && ori2enc[ori] != enc) {
      cout << "Pak Dengklek bingung";
      return 0;
    }

    if (enc2ori.count(enc) && enc2ori[enc] != ori) {
      cout << "Pak Dengklek bingung";
      return 0;
    }
    ori2enc[ori] = enc;
    enc2ori[enc] = ori;
  }

  string final = "";
  for (const char &letter : p3) {
    if (enc2ori.count(letter)) {
      final += enc2ori[letter];
    } else {
      final += '?';
    }
  }

  cout << final;
  return 0;
}
