#include <bits/stdc++.h>

using namespace std;

struct node {
  int id;
  int weight;
};

struct last_node {
  int id;
  int total_sum;
};

last_node obtain_max(vector<node> nodes_list, vector<vector<int>> adj_matrix,
                     int node_id, int sum) {

  node actual_node = nodes_list[node_id];
  node next_node = {0, 0};
  bool flag = true;
  for (int i = 0; i < nodes_list.size(); ++i) {
    if (adj_matrix[node_id][i] == 1) {
      flag = false;
      node temp = nodes_list[i];
      if (temp.weight > next_node.weight) {
        next_node = temp;
      }
    }
  }
  last_node final = {node_id, sum};

  if (!flag)
    return obtain_max(nodes_list, adj_matrix, next_node.id,
                      sum + next_node.weight);
  else
    return final;
}

int main() {

  int test_cases;
  cin >> test_cases;
  while (test_cases--) {
    int j = 0;
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int>> adj_matrix(nodes, vector<int>(nodes, 0));
    vector<node> nodes_list;

    for (int i = 0; i < nodes; ++i) {
      int weight;
      cin >> weight;
      nodes_list.push_back({i, weight});
    }
    for (int i = 0; i < edges; ++i) {
      int u, v;
      cin >> u >> v;
      adj_matrix[u][v] = 1;
    }

    int max_sum = 0;
    last_node last;
    last = obtain_max(nodes_list, adj_matrix, 0, nodes_list[0].weight);
    cout << "Case " << j + 1 << ": " << last.total_sum << " " << last.id
         << endl;
  }

  return 0;
}
