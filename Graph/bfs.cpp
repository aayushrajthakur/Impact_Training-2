#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool> visited){
    queue<int> q;
    visited[node]= true;
    q.push(node);

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        cout<<curr<<" ";
        for(int it: graph[curr]){
            if(!visited[it]){
                visited[it]= true;

                q.push(it);
            }
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
    
    dfs(src,graph, visited);

    return 0;
}