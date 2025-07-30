#include<iostream>
#include<vector>
using namespace std;

bool graphColoring(vector<vector<bool>>& graph){
    int m = graph.size();
    vector<int> color(m, 0);
}

int main()
{
    vector<vector<bool>> graph = {{0,1,1,1,0},{0,0,1,1,0},{1,1,0,0,1},{1,1,0,0,1},{0,0,1,1,0}};
    graphColoring(graph);

    return 0;
}





