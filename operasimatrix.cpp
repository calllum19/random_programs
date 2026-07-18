#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> transpose(const vector<vector<int>> &M1) {
  vector<vector<int>> M2(M1[0].size(), vector<int>(M1.size(), 0));
  for (int i = 0; i < M2.size(); ++i) {
    for (int j = 0; j < M2[0].size(); ++j) {
      M2[i][j] = M1[j][i];
    }
  }
  return M2;
}

vector<vector<int>> operations(vector<vector<int>> &M1,
                               const vector<string> &method) {
  for (string value : method) {
    if (value == "_") {
      reverse(M1.begin(), M1.end());
    } else if (value == "|") {
      for (int j = 0; j < M1.size(); ++j) {
        reverse(M1.at(j).begin(), M1.at(j).end());
      }
    } else if (value == "90") {
      M1 = transpose(M1);
      for (int j = 0; j < M1.size(); ++j) {
        reverse(M1.at(j).begin(), M1.at(j).end());
      }
    } else if (value == "180") {
      reverse(M1.begin(), M1.end());
      for (int j = 0; j < M1.size(); ++j) {
        reverse(M1.at(j).begin(), M1.at(j).end());
      }
    } else if (value == "270") {
      M1 = transpose(M1);
      reverse(M1.begin(), M1.end());
    }
  }
  return M1;
}

int main(int argc, char *argv[]) {
  int inputN, inputM, inputX;
  cin >> inputN >> inputM >> inputX;

  vector<vector<int>> M1(inputN, vector<int>(inputM, 0));
  for (int i = 0; i < inputN; i++) {
    for (int j = 0; j < inputM; j++) {
      cin >> M1[i][j];
    }
  }
  vector<string> method(inputX);
  for (int i = 0; i < inputX; ++i) {
    cin >> method[i];
  }

  M1 = operations(M1, method);
  // results printed
  int count = 0;
  for (const auto &row : M1) {
    for (int value : row) {
      count++;
      if (count < M1.begin()->size()) {
        cout << value << " ";
      } else {
        cout << value << "\n";
        count = 0;
      }
    }
  }
  return 0;
}
