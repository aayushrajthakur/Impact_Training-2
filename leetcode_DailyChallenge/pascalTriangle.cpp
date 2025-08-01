#include<iostream>
#include<vector>
using namespace std;


vector<vector<int>> pascalTriangle(int n){
    vector<vector<int>> sq;
    for(int row = 0; row < n; row++){
        vector<int> currentFlow;
        int c = 1;
        for(int i=0; i <= row; i++){
            currentFlow.push_back(c);
            c = c * (row - i) / (i + 1);

        }
        sq.push_back(currentFlow);
    }
    return sq;
}


int main()
{
    int n = 5;
    vector<vector<int>> res = pascalTriangle(n);
    for(int i=0; i< res.size(); i++){
        for(int j=0; j< res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}