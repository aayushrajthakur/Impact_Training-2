#include<iostream>
using namespace std;

int main()
{
    int i = 0;
    while (i<8)
    {
        do
        {
            i++;
            if(i==3){
                break;
            }
            cout<<i<<endl;
        } while (i<5);
        
    }
    
    return 0;
}