#include <iostream>
#include <vector>
using namespace std;

int main(){
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int>> matrix(nodes, vector<int>(nodes, 0));

    for(int i = 0; i < edges; i++){
        int a, b;
        cin >> a >> b;
        matrix[a - 1][b - 1] = 1;
        matrix[b - 1][a - 1] = 1;
    }

    for(int i = 0; i < nodes; ++i)
        for(int j = 0; j < nodes; ++j)
            cout << matrix[i][j] << " \n"[j == nodes - 1];

    return 0;
}
