#include<iostream>
using namespace std;
int findGCD(int a, int b){
    while(b != 0){
        int temp = b;
        b = a% b;
        a = temp;
    }
    return a;
}

int main()
{
    int x,y;
    cin>>x>>y;
    
    int gcd = findGCD(x, y);
    cout<<(x+y)/gcd;
}