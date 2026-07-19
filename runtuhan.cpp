#include <bits/stdc++.h>
using namespace std;

// Wipe rows filled with 1s, maybe I could do the falling here too, and make it
// recursive?
void wipefull(vector<vector<char>> &board) {
  bool successful = false;
  for (vector<char> &row : board) {
    if (all_of(row.begin(), row.end(), [](char x) { return x == '1'; })) {
      for (char &value : row) {
        value = '0';
      }
      successful = true;
    }
  }
  if (successful) {
    // write falling logic (NOTE; it can only affect the lines above the
    // destroyed lines )
    successful = false;
    for (int j = 0; j < board.begin()->size(); ++j) {
      int groundzero = -1;
      for (int i = board.size() - 1; i >= 0; --i) {
        if (board[i][j] == '0' && groundzero == -1) {
          groundzero = i;
        } else if (board[i][j] == '0' && groundzero != -1) {
          continue;
        } else if (board[i][j] == '1' && i < groundzero) {
          board[i][j] = '0';
          board[groundzero][j] = '1';
          while (groundzero >= 0 && board[groundzero][j] == '1') {
            groundzero -= 1;
          }
        } else {
          continue;
        }
      }
    }
    wipefull(board);
  }
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // rows and columns
  int R;
  int C;
  cin >> R >> C;
  vector<vector<char>> board(R, vector<char>(C));
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      cin >> board[i][j];
    }
  }

  wipefull(board);

  // print the board
  for (const vector<char> &row : board) {
    for (char value : row) {
      cout << value;
    }
    cout << '\n';
  }
  return 0;
}
