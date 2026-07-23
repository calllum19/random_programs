#include <bits/stdc++.h>
using namespace std;

int firstduck(const vector<int> &duck, const pair<int, int> &cond) {
  int left = 0, right = duck.size() - 1;
  int result = -1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (duck[mid] > cond.first && duck[mid] <= cond.second) {
      result = mid;
      right = mid - 1;
    } else if (duck[mid] <= cond.first) {
      left = mid + 1;
    } else { // duck mid > cond.second
      right = mid - 1;
    }
  }
  return result;
}

int lastduck(const vector<int> &duck, const pair<int, int> &cond) {
  int left = 0, right = duck.size() - 1;
  int result = -1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (duck[mid] > cond.first && duck[mid] <= cond.second) {
      result = mid + 1;
      left = mid + 1;
    } else if (duck[mid] <= cond.first) {
      left = mid + 1;
    } else { // duck mid > cond.second
      right = mid - 1;
    }
  }
  return result;
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  int Q;
  cin >> Q;
  vector<pair<int, int>> between(Q);
  for (int i = 0; i < Q; ++i) {
    cin >> between[i].first >> between[i].second;
  }

  for (int i = 0; i < Q; ++i) {
    cout << lastduck(A, between[i]) - firstduck(A, between[i]) << '\n';
  }
  return 0;
}
