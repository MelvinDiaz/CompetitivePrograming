#include <bits/stdc++.h>
using namespace std;

long long fibonacci(long long n, vector<long long> &memo) {
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

  vector<long long> memo(100000000, -1);
  cout << fibonacci(n, memo) << endl;
  return 0;
}
