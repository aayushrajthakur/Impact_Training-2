#include<iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int val){
        this->val = val;
        this->next = nullptr;
    }
};

class Graph{
    public:
    int n = 5;
    vector<Node*> nodes;
    
    Graph() {
        nodes.resize(n,nullptr);
    }

    void addEdge(int a, int b){
        if (a < 0 || a >= n || b < 0 || b >= n) {
            cout << "Error: Vertex index out of bounds." << endl;
            return;
        }
        if(!nodes[a]) nodes[a] = new Node(a);
        if(!nodes[b]) nodes[b] = new Node(b);

        Node* temp  = nodes[a];
        while(temp->next) temp = temp->next;
        temp->next = new Node(b);

        temp = nodes[b];
        while(temp->next) temp = temp->next;
        temp->next = new Node(a);
    }

    void print() {
        for(int i=0;i<=n;i++){
            if(!nodes[i]) continue;
            Node* temp = nodes[i];
            cout<<"vertex "<<temp->val<<": ";
            while(temp){
                cout<<temp->val<<" -> ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }
};

int main()
{
    int a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;

    Graph graph;
    graph.addEdge(a,b);
    graph.addEdge(b,c);
    graph.addEdge(c,d);
    graph.addEdge(d,e);
    graph.addEdge(a,e);
    graph.addEdge(b,e);
    graph.addEdge(b,d);

    graph.print();

    return 0;
}