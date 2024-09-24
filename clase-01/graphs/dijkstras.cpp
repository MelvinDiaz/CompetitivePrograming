#include <iostream>
#include <queue>
#include <climits>
#include <vector>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S){
    //Declare the minimun heap
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    // Vector array of same size
    vector<int> dist(V,INT_MAX);

    // The source will always be 0
    dist[S] = 0;
    pq.push({0,S});

    // Loop until the min heap is empty
    while(!pq.empty()){
        // Get the top element
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();


        for(auto it : adj[node]){
            // Get the adjacent node and the weight
            int edgeWeight = it[1];
            int adjNode = it[0];

            // Check if its already visited and if the distance is less than the current distance
            if(dis + edgeWeight < dist[adjNode]){
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    // Return the distance array for each node
    return dist;
}

int main(){
    int vertices, edges;
    cin >> vertices;
    // Initialize the adjacency list
    vector<vector<int>> adj[vertices];
    cin >> edges;

    // Input the edges and the weight
    for(int i = 0; i < edges; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        // The u position, put the connection and the weight
        adj[u].push_back({v, w});
    }

    cout << "\nInput the source: ";
    int source;
    cin >> source;
    vector<int> dist = dijkstra(vertices, adj, source);

    cout << "The distances from the source are: ";
    for(int i = 0; i < vertices; ++i)
        cout << dist[i] << " ";

    cout << "\n";
    return 0;
}
