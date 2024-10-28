#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// Fenwick Tree methods
int sum(int i, vector<int> &T) {
  int total = 0;
  while (i > 0) {
    total += T[i];
    i -= i & -i;
  }
  return total;
}

void add(int i, int k, vector<int> &T) {
  while (i < T.size()) {
    T[i] += k;
    i += i & -i;
  }
}

// Calculate prefix counts
void calculate_prefix(int a[], vector<int> &prefix, int n) {
  unordered_map<int, int> count_map;
  for (int i = 1; i <= n; ++i) {
    count_map[a[i]]++;
    prefix[i] = count_map[a[i]];
  }
}

// Calculate suffix counts
void calculate_suffix(int a[], vector<int> &suffix, int n) {
  unordered_map<int, int> count_map;
  for (int i = n; i >= 1; --i) {
    count_map[a[i]]++;
    suffix[i] = count_map[a[i]];
  }
}

int main() {
  int n;
  cin >> n;

  vector<int> a(n + 1); // Using vector to prevent stack overflow on large n
  vector<int> prefix(n + 1);
  vector<int> suffix(n + 1);

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  // Calculate prefix and suffix arrays
  calculate_prefix(a.data(), prefix, n);
  calculate_suffix(a.data(), suffix, n);

  // Find the maximum value in the array for the Fenwick Tree size
  int max_value = *max_element(a.begin() + 1, a.end());
  vector<int> fenwick_tree(max_value + 1, 0);
  long long valid_pairs = 0;

  // Count valid pairs (i, j)
  for (int j = 1; j <= n; ++j) {
    // For each j, count how many prefix[i] are greater than suffix[j]
    if (j > 1) { // Ensure that j > i
      valid_pairs +=
          sum(max_value, fenwick_tree) - sum(suffix[j] - 1, fenwick_tree);
    }
    // Update the Fenwick Tree with the current prefix[j - 1]
    add(prefix[j - 1], 1, fenwick_tree); // Increase count of prefix[j - 1]
  }

  cout << valid_pairs << "\n";
  return 0;
}
