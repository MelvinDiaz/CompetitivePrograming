#include <bits/stdc++.h>
#include <vector>
using namespace std;

long long gridTraveler(int m, int n, vector<vector<long long>> &memo) {
  if (memo[m][n] != -1)
    return memo[m][n];
  if (m == 1 && n == 1)
    return 1;
  if (m == 0 || n == 0)
    return 0;

  memo[m][n] = gridTraveler(m - 1, n, memo) + gridTraveler(m, n - 1, memo);
  return memo[m][n];
}

int main() {
  int n, m;
  cin >> m >> n;
  vector<vector<long long>> memo(
      m + 1, vector<long long>(n + 1, -1)); // 2d array full with -1
  cout << gridTraveler(m, n, memo) << endl;

  return 0;
}
