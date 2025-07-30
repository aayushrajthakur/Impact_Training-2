#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int findShortestCycle(int n, vector<vector<int>>& edges) {
    vector<vector<int>> graph(n);
    for (const auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]); // Undirected graph
    }

    int minCycleLength = INT_MAX;

    for (int start = 0; start < n; ++start) {
        vector<int> dist(n, INT_MAX);
        vector<int> parent(n, -1);
        queue<int> q;
        
        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (int neighbor : graph[node]) {
                if (dist[neighbor] == INT_MAX) { 
                    dist[neighbor] = dist[node] + 1;
                    parent[neighbor] = node;
                    q.push(neighbor);
                } else if (parent[node] != neighbor) { 
                    minCycleLength = min(minCycleLength, dist[node] + dist[neighbor] + 1);
                }
            }
        }
    }

    return (minCycleLength == INT_MAX) ? -1 : minCycleLength;
}

int main() {
    int n, m;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(2));
    cout << "Enter edges (format: node1 node2):\n";
    for (int i = 0; i < m; ++i) {
        cin >> edges[i][0] >> edges[i][1];
    }

    int result = findShortestCycle(n, edges);
    if (result != -1)
        cout << "The shortest cycle length is: " << result << endl;
    else
        cout << "No cycle found!" << endl;

    return 0;
}
