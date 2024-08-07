#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n, vector<int> &memo) {
  if (memo[n] != -1)
    return memo[n];
  if (n <= 2)
    return 1;

  memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
  return memo[n];
}

int main() {
  int n;
  cin >> n;

  vector<int> memo(100000000, -1);
  cout << fibonacci(n, memo) << endl;
  return 0;
}
