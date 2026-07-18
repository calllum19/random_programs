#include <iostream>
#include <vector>
using namespace std;

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
  cin >> method;
  if (method == "_") {
    reflect(M1, 0);
  } else if (method == "|") {
    reflect(M1, 1);
  } else if (method == "90") {
    reflect
  }
  return 0;
}
