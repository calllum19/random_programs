#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  int inputN, inputM;
  cin >> inputN;
  cin >> inputM;

  vector<vector<int>> M1(inputN, vector<int>(inputM, 0));
  vector<vector<int>> M2(inputM, vector<int>(inputN, 0));

  for (int i = 0; i < inputN; i++) {
    for (int j = 0; j < inputM; j++) {
      cin >> M1[i][j];
      M2[j][inputN - i - 1] = M1[i][j];
    }
  }
  // would you look at the time?
  int count = 0;
  for (const auto &row : M2) {
    for (int value : row) {
      count++;
      if (count < inputN) {
        cout << value << " ";
      } else {
        cout << value << "\n";
        count = 0;
      }
    }
  }

  return 0;
}
