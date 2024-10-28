#include <iostream>
using namespace std;

int main() {
  int t;
  int n;
  cin >> n >> t;
  int left = 0;
  int right = 0;
  int maxBooks = 0;
  int arr[n];
  int tAux = 0;

  for (int i = 0; i < n; ++i) cin >> arr[i];

  while(right < n){
    tAux += arr[right];

    while(tAux > t){
      tAux -= arr[left];
      left++;
    }

    maxBooks = max(right - left + 1, maxBooks);
    right++;
  }
  

  cout << maxBooks << "\n";

  return 0;
}