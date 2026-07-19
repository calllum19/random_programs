#include <bits/stdc++.h>
using namespace std;

void wipeit(vector<vector<char>> &board) {
  // Deletion. Bool tracks if it was successful, if it wasnt then it wont recall
  // function
  bool success = false;
  // This int tracks the last line deleted, so that 1s
  // currently floating dont fall down.
  int gzlimit = -1;
  for (int i = 0; i < board.size(); ++i) {
    if (count(board[i].begin(), board[i].end(), '1') == board[i].size()) {
      board[i].assign(board[i].size(), '0');
      success = true;
      gzlimit = i;
    }
  }
  if (success) {
    success = false;
    // Since it did wipe, lets introduce gravity to the remaining 1s
    for (int j = 0; j < board.begin()->size(); ++j) {
      int groundzero = -1;
      for (int i = board.size() - 1; i >= 0; --i) {
        // We start from bottom up first to
        // find where the ones should land.
        if (groundzero == -1 && board[i][j] == '0') {
          groundzero = i;
        } else if (groundzero != -1 && board[i][j] == '0') {
          continue;
        } else if (board[i][j] == '1' && i < gzlimit) {
          board[i][j] = '0';
          board[groundzero][j] = '1';
          --groundzero;
        } else if (board[i][j] == '1') {
          groundzero = i - 1;
        }
      }
    }
    wipeit(board);
  }
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // 1. Initialize variables
  int R, C;
  cin >> R >> C;
  vector<vector<char>> board(R, vector<char>(C));
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      cin >> board[i][j];
    }
  }

  // 2. Call a recursive function that wipes and makes 1s fall.
  wipeit(board);
  // 3. Print the board once wipeit's done.
  for (auto &row : board) {
    for (char &value : row) {
      cout << value;
    }
    cout << "\n";
  }
  return 0;
}
