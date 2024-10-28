#include <iostream>
using namespace std;

int main() {
  string input;
  int k;
  int maxVowels = 0;
  int total = 0;

  cin >> input;
  cin >> k;
  k--;

  for (int i = 0; i <= k; ++i) {
    if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' ||
        input[i] == 'o' || input[i] == 'u') {
      maxVowels++;
      total++;
    }
  }

  for (int i = 1; i < input.length() - k; ++i) {
    if (input[i + k] == 'a' || input[i + k] == 'e' || input[i + k] == 'i' ||
        input[i + k] == 'o' || input[i + k] == 'u') {
      total++;
    }
    if (input[i - 1] == 'a' || input[i - 1] == 'e' || input[i - 1] == 'i' ||
        input[i - 1] == 'o' || input[i - 1] == 'u') {
      total--;
    }

    maxVowels = max(total, maxVowels);
  }

  cout << maxVowels << '\n';

  return 0;
}