#include<iostream>
#include<vector>
using namespace std;

void dfs(int start, vector<vector<int>> &graph, vector<bool> visited){
    visited[start] = true;
    for(int neighbour : graph[start]){

        if(!visited[neighbour]) {
            cout<<neighbour<<" ";
            dfs(neighbour, graph, visited);
        }
    }
}

int main()
{
    int vertices;
    cin>>vertices;

    int edges;
    cin>>edges;

    vector<vector<int>> graph(vertices);
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        //graph[v].push_back(u);
    }

    vector<bool> visited(vertices,false);
    int src;
    cin>>src;
    cout<<src<<" ";
    dfs(src,graph, visited);

    return 0;
}