#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int m;
    cin>>m;

    vector<vector<int>> matrix(m, vector<int>(m));
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            cin>>matrix[i][j];
        }
    }
    int count = 0;

    for(int i=0; i<m; i++){
        bool flag = true;
        for(int j=0; j<m-1; j++){
            if(!(matrix[i][j] <= matrix[i][j+1])){
                flag = false;
                break;
            }
        }
        if(flag){
            count++;
        }
    }

    cout<<"No of sorted rows : "<<count<<endl;
    return 0;
}