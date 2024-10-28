#include <iostream>

using namespace std;

int main() {
  int arr[23] = {12, 9,  23, 17, 25, 19, 4, 8,  21, 34, 26, 17,
                 19, 14, 27, 22, 15, 7,  2, 14, 5,  18, 24};
  int total = 0, maximo = 0, n = 23, window = 4;

  for (int i = 0; i <= window; ++i) total += arr[i];

  for (int i = 1; i < n - window; ++i) {
    total = total + arr[i + 4] - arr[i - 1];
    maximo = max(maximo, total);
  }

  cout << maximo << '\n';
  return 0;
}