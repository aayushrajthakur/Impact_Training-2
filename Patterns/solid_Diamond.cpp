#include<iostream>
using namespace std;

void print_SolidDiamond(int m){
    int space = m - 1;

    for(int i=0; i<m; i++){

        for(int j=0; j<space; j++){
            cout<<" ";
        }

        for(int j=0; j <= i; j++){
            cout<<"* ";
        }
        cout<<endl;
        space--;
    }

    space = 0;
    for(int i= m-1; i >= 0; i--){
        for(int j=0; j< space; j++){
            cout<<" ";
        }

        for(int j=0; j<= i; j++){
            cout<<"* ";
        }

        space++;
        cout<<endl;
    }
}

int main()
{
    int m;
    cin>>m;

    print_SolidDiamond(m);
    return 0;
}