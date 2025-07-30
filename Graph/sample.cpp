#include <iostream>
#include <vector>
#include <queue>
#include <utility> 
#include <limits>  

using namespace std;

const int INF = numeric_limits<int>::max(); 
void dijkstra(int source, const vector<vector<pair<int, int>>>& graph, vector<int>& distances) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap
    distances[source] = 0; 
    pq.push({0, source}); 
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            
            if (distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                pq.push({distances[v], v}); 
            }
        }
    }
}

int main() {
    int V = 5; 
    vector<vector<pair<int, int>>> graph(V);
    graph[0].push_back({2, 5});
    graph[0].push_back({1, 4});
    graph[0].push_back({3, 1});
    graph[1].push_back({3, 1});
    graph[1].push_back({1, 2});
    graph[3].push_back({4, 2});
    graph[2].push_back({4, 5});

    vector<int> distances(V, INF); 
    dijkstra(0, graph, distances); 

    
    for (int i = 0; i < V; i++) {
        cout << "Distance from source to vertex " << i << " is " << distances[i] << endl;
    }

    return 0;
}
