#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int m;
    cin>>m;

    vector<vector<int>> matrix(m, vector<int>(m, 0));
    
    int c;
    while(true){
        cout<<"Enter the choice (1 or -1): ";
        cin>>c;
        if(c == 1){
            int i,j;
            cout<<"Enter the  elements of the matrix at particular index seperated by space : ";
            cin>>i>>j;
            if(i < m && j < m){
                int val;
                cout<<"\nEnter the value (0 or 1) :  ";
                cin>>val;
                matrix[i][j] = val;
            }else {
                cout<<"Out of bound, Try again !!\n";
            }
        }else {
            break;
        }
    }
    int flag = true;
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++) {
            if(j < i){
                if(matrix[i][j] == 1){
                    flag = false;
                }
            }
        }
    }
    if(flag){
        cout<<"The given matrix is upper triangular matrix..";
    }else {
        cout<<"The given matrix is not upper triangular matrix..";
    }
    return 0;
}