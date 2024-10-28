#include <iostream>
using namespace std;

int main() {
  int t;
  int n;
  cin >> n >> t;
  int total = 0;
  int maximo = 0;

  int arr[n];

  for (int i = 0; i < n; ++i) cin >> arr[i];

  int tAux = t;

  for (int i = 0; i < n; ++i) {
    if (tAux == 0) break;
    tAux -= arr[i];
    if (tAux >= 0) {
      maximo++;
      total++;
    }
  }


  for (int i = 1; i < n; ++i) {
    if (maximo == n) break;
    total = 0;
    tAux = t;
    if (tAux - arr[i] >= 0) {
      total++;
      tAux -= arr[i];
    }

    for (int j = i + 1; j < n; ++j) {
      if (tAux <= 0) break;
      tAux -= arr[j];
      if (tAux >= 0) {
        total++;
      }
      if (tAux - arr[j + 1] <= 0 && j + 1 <= n) break;
    }

    maximo = max(maximo, total);
  }

  cout << maximo << '\n';

  return 0;
}
