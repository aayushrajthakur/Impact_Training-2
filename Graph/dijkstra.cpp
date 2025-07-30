#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> node;
const int INF = INT_MAX;

vector<int> dijkstra(const int vertex, vector<vector<node>>& graph, int src){
    priority_queue<node, vector<node>, greater<node>> pq;

    vector<int> distance(vertex, INF);

    distance[src]= 0;
    pq.push({0,src});

    while(!pq.empty()){
        int dis = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        for(auto it: graph[u]){
            int edgeWeight = it.second;
            int adjNode = it.first;

            if(dis+ edgeWeight < distance[adjNode]){
                distance[adjNode] = dis + edgeWeight;
                pq.push({ distance[adjNode], adjNode});
            }
        }
    }

    return distance;
}

int main()
{
    int vertex, edges;
    cin>>vertex>>edges;

    vector<vector<node>> graph(edges);
    for(int i=0;i<edges;i++){
        int from,to,weight;
        cin>>from>>to>>weight;

        //if the graph is undirected graph
        graph[from].push_back({to, weight});
        //remove the below line if the graph is directed.
        graph[to].push_back({from,weight});
    }
    int source, destination;
    cin>>source>>destination;

    vector<int> distance;
    distance = dijkstra(vertex, graph, source);

    for(int i=0;i<vertex; i++){
        cout<<i<<" -> "<<distance[i]<<endl;
    }


    return 0;
}