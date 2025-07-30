#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int node) {
        if (parent[node] != node)
            parent[node] = find(parent[node]);
        return parent[node];
    }

    void union_sets(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        if (root_u != root_v) {
            if (rank[root_u] > rank[root_v])
                parent[root_v] = root_u;
            else if (rank[root_u] < rank[root_v])
                parent[root_u] = root_v;
            else {
                parent[root_v] = root_u;
                rank[root_u]++;
            }
        }
    }
};

vector<Edge> kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    DisjointSet ds(n);
    vector<Edge> mst;

    for (const Edge& edge : edges) {
        if (ds.find(edge.u) != ds.find(edge.v)) {
            mst.push_back(edge);
            ds.union_sets(edge.u, edge.v);
        }
    }

    return mst;
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> adjMatrix(n, vector<int>(n));
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adjMatrix[i][j];

    vector<Edge> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (adjMatrix[i][j] > 0) {
                edges.push_back({i, j, adjMatrix[i][j]});
            }
        }
    }

    vector<Edge> mst = kruskal(n, edges);

    cout << "Minimum Spanning Tree edges:\n";
    for (const Edge& edge : mst) {
        cout << edge.u << " - " << edge.v << " : " << edge.weight << endl;
    }

    return 0;
}
