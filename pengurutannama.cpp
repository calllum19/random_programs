#include <bits/stdc++.h>
#include <utility>
using namespace std;

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  vector<string> nama(N);
  for (int i = 0; i < N; ++i)
    cin >> nama[i];
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N - i - 1; ++j) {
      if (nama[j].size() > nama[j + 1].size())
        swap(nama[j], nama[j + 1]);
      else if (nama[j].size() == nama[j + 1].size())
        if (nama[j] > nama[j + 1])
          swap(nama[j], nama[j + 1]);
    }
  }
  for (const string &s : nama)
    cout << s << '\n';
  return 0;
}
