#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int operations(vector<vector<int>> M1, string &method, int &derajat, int &X) {
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
      break;
    case 180:
      break;
    case 270:
      break;
    }
  }
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

  operations(M1, method, derajat, inputX);
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
