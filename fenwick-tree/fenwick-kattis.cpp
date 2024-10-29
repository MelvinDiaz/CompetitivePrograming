#include <bits/stdc++.h>
using namespace std;

long long sum(long long i, long long T[]) {
  long long sum = 0;

  while (i > 0) {
    sum += T[i];
    i -= i & -i;
  }

  return sum;
}

void add(long long i, long long k, long long T[], long long n) {
  while (i <= n) {
    T[i] += k;
    i += i & -i;
  }
}

int main() {

  long long n, c;
  cin >> n >> c;

  long long a[n + 1];
  long long t[n + 1];

  // Fill with 0 the fenwick tree
  fill(t, t + n + 1, 0);

  string output;

  while (c--) {
    char o;
    long long i, j;
    cin >> o;
    if (o == '+') {
      cin >> i >> j;
      add(i + 1, j, t, n);

    } else {
      cin >> i;
      if (i == 0)
        output += "0\n";
      else
        output += to_string(sum(i, t)) + "\n";
    }
  }

  cout << output;

  return 0;
}
