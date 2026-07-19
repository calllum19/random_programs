#include <bits/stdc++.h>
using namespace std;

void wipefull(vector<vector<char>> &board) {
  for (vector<char> &row : board) {
    if (all_of(row.begin(), row.end(), [](char x) { return x == '1'; })) {
      for (char &value : row) {
        value = '0';
      }
    }
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
