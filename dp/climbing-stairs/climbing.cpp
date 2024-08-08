#include <bits/stdc++.h>

using namespace std;

int climbStairs(int n, int s, vector<int> &memo) {
  if (s > n)
    return 0;
  if (s == n)
    return 1;
  if (memo[s] != -1)
    return memo[s];

  memo[s] = climbStairs(n, s + 1, memo) + climbStairs(n, s + 2, memo);
  return memo[s];
}

int main() {

  int n;
  cin >> n;
  vector<int> memo(n + 1, -1);
  cout << climbStairs(n, 0, memo) << endl;

  return 0;
}
