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

vector<vector<int>> operations(vector<vector<int>> M1, string &method,
                               int &derajat, int &X) {
  for (int i = 0; i < X; ++i) {
    if (method == "_") {
      reverse(M1.begin(), M1.end());
    } else if (method == "|") {
      for (int j = 0; j < M1.size(); ++j) {
        reverse(M1.at(j).begin(), M1.at(j).end());
      }
    }
    switch (derajat) {
    case 90:
      M1 = transpose(M1);
      for (int j = 0; j < M1.size(); ++j) {
        reverse(M1.at(j).begin(), M1.at(j).end());
      }
      break;
    case 180:
      reverse(M1.begin(), M1.end());
      for (int j = 0; j < M1.size(); ++j) {
        reverse(M1.at(j).begin(), M1.at(j).end());
      }
      break;
    case 270:
      M1 = transpose(M1);
      reverse(M1.begin(), M1.end());
      break;
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
  string method;
  int derajat;
  cin >> method >> derajat;

  M1 = operations(M1, method, derajat, inputX);
  // results printed
  int count = 0;
  for (const auto &row : M1) {
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
