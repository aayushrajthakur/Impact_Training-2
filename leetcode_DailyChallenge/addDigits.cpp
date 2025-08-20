#include<iostream>
using namespace std;

int addDigits(int m){
    return (m == 0) ? 0 : 1 + (m - 1)%9;
}

int main()
{
    int m;
    cin>>m;

    cout<<addDigits(m);
    return 0;
}