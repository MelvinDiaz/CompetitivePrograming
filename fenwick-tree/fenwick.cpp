#include <bits/stdc++.h>
using namespace std;

int sum(int i, int T[]) {
  int sum = 0;

  while (i > 0) {
    sum += T[i];
    i -= i & -i;
  }

  return sum;
}

void add(int i, int k, int T[], int n) {
  while (i < n) {
    T[i] += k;
    i += i & -i;
  }
}

/*15*/
/*5 2 9 -3 5 20 10 -7 2 3 -4 0 -2 15 5*/

int main() {

  int n;
  cin >> n;

  int a[n + 1];
  int t[n + 1];

  for (int i = 1; i <= n; ++i)
    cin >> a[i];

  // linear time creation of fenwick tree
  copy(a, a + n, t);

  for (int i = 1; i <= n; ++i) {
    int p = i + (i & -i);
    if (p < n) {
      t[p] = t[p] + t[i];
    }
  }

  add(4, 10, t, n);

  cout << sum(7, t);

  return 0;
}
