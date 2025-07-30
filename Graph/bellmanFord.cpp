#include<iostream>
#include<vector>
#include<climits>

const int MAX = INT_MAX;
using namespace std;

vector<int> bellManFord(int vertex, vector<vector<int>>& edges, int src){
    vector<int> dist(vertex, MAX);

    dist[src] = 0;
    for(int i=0;i<vertex;i++){
        for(vector<int> edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if(dist[u] != MAX && dist[u] + w < dist[v]){
                if(i == vertex-1){
                    return {-1};
                }
                dist[v] = w + dist[u];

            }

        }
    }
    return dist;
}

int main()
{
    int v, n;
    cin>>v>>n;

    vector<vector<int>> edges(n, vector<int>(3));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>edges[i][j];
        }
    }

    int src;
    cin>>src;

    vector<int> res = bellManFord(v, edges, src);
    for(int dist: res){
        cout<<dist<<" ";
    }
    return 0;
}