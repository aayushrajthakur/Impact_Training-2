#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> moveZeros(vector<vector<int>>& matrix, int m, int n){
    vector<vector<bool>> check(m, vector<bool>(n, false));
    for(int i=0; i< matrix.size(); i++){
        for(int j=0; j< matrix[i].size(); j++){
            if(matrix[i][j] == 0){
                check[i][j] = true;
            }
        }
    }
    for(int i=0; i< matrix.size(); i++){
        for(int j=0; j< matrix[i].size(); j++){
            if(check[i][j] == true){
                if(i > 0){
                    matrix[i-1][j] = 0;
                }
                if(i < n - 1){
                    matrix[i + 1][j] = 0;
                }
                if(j > 0){
                    matrix[i][j + 1] = 0;
                }
                if(j < n -1){
                    matrix[i][j - 1] = 0;
                }
            }
        }
    }
    return matrix;
}

int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for(int i=0; i< m; i++){
        for(int j=0; j< n; j++){
            cin>>matrix[i][j];
        }
    }
    cout<<"The output is : "<<endl;
    vector<vector<int>> res = moveZeros(matrix, m, n);
    for(int i=0; i< m; i++){
        for(int j=0; j< n; j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}