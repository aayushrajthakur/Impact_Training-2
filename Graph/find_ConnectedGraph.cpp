#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

vector<vector<pair<int, int>>> buildGraph(int n, const vector<vector<int>>& edges) {
    vector<vector<pair<int, int>>> graph(n);
    for (size_t i = 0; i < edges.size(); ++i) {
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w)); // Bidirectional edge
    }
    return graph;
}

vector<int> dijkstra(int n, const vector<vector<pair<int, int>>>& graph, int start, int threshold) {
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        pair<int, int> topElement = pq.top(); pq.pop();
        int d = topElement.first;
        int node = topElement.second;

        if (d > dist[node]) continue;

        for (size_t i = 0; i < graph[node].size(); ++i) {
            int neighbor = graph[node][i].first;
            int weight = graph[node][i].second;
            
            if (dist[node] + weight <= threshold && dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                pq.push(make_pair(dist[neighbor], neighbor));
            }
        }
    }

    return dist;
}

int findCity(int n, const vector<vector<int>>& edges, int threshold) {
    vector<vector<pair<int, int>>> graph = buildGraph(n, edges);
    int bestCity = -1, minReachable = INT_MAX;

    for (int i = 0; i < n; ++i) {
        vector<int> dist = dijkstra(n, graph, i, threshold);
        int reachableCount = 0;

        for (int j = 0; j < n; ++j) {
            if (i != j && dist[j] <= threshold) {
                reachableCount++;
            }
        }

        if (reachableCount < minReachable || (reachableCount == minReachable && i > bestCity)) {
            minReachable = reachableCount;
            bestCity = i;
        }
    }

    return bestCity;
}

int main() {
    int n, m, threshold;
    cout << "Enter number of cities (nodes): ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;
    cout << "Enter distance threshold: ";
    cin >> threshold;

    vector<vector<int>> edges(m, vector<int>(3));
    cout << "Enter edges (format: city1 city2 distance):\n";
    for (int i = 0; i < m; ++i) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int result = findCity(n, edges, threshold);
    cout << "The city with the smallest number of reachable cities within the threshold is: " << result << endl;

    return 0;
}
