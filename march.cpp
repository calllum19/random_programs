#include <iostream>
#include <string>
#include <vector>

long long findways(const std::vector<std::string> &people) {
  std::string march = "MARCH";
  char first;
  std::vector<long long> counts(march.size(), 0);
  for (const std::string &person : people) {
    first = person.front();
    int findit = march.find(first);
    if (person == "") {
      continue;
    }
    if (findit != std::string::npos) {
      ++counts[findit];
    } else {
      continue;
    }
  }
  long long result = 0;
  for (int i = 0; i < 5; ++i) {
    for (int j = i + 1; j < 5; ++j) {
      for (int k = j + 1; k < 5; ++k) {
        result += counts[i] * counts[j] * counts[k];
      }
    }
  }
  return result;
}

int main() {
  int N;
  std::cin >> N;
  std::vector<std::string> people(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> people[i];
  }

  std::cout << findways(people);

  return 0;
}
