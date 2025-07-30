#include<iostream>
using namespace std;

void directedGraph(int v) {
    int arr[v][v];
    for(int i=0;i<v;i++){
        cout<<"Enter the connections with node "<<i<<" : ";
        for(int j=0;j<v;j++){
            cin>>arr[i][j];
        }
    }
}
int main()
{
    int choice,vertex;
    cout<<endl;
    cout<<"\033[1mGraph Tutorial using Matrix Representation : \033[0m \n";
    cout<<"1. Directed Graph"<<endl;
    cout<<"2. Undirected Graph"<<endl;

    cout<<"\nEnter the vertex count : ";
    cin>>vertex;
    
    cout<<"Enter your choice : ";
    cin>>choice;
    if(choice == 1){
        directedGraph(vertex);
    }else if(choice == 2){
        undirectedGraph(vertex);
    }else {
        cout<<"Invalid choice ";
    }
    return 0;
}