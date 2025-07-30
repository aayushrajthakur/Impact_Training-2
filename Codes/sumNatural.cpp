#include<iostream>
using namespace std;
int sumNatural(int n){
    if(n == 0){
        return 1;
    }
    return n+ sumNatural(n-1);
}
int main()
{
    cout<<"Sum of natural numbers : ";
    cout<<sumNatural(10);
    return 0;
}