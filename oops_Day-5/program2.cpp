#include<iostream>
using namespace std;
class Cricket{
    public:
    int a;

    Cricket(int a){
            this->a=a;
    }
   
};
int main()
{
    Cricket sachin(10);
    cout<<sachin.a;
    return 0;
}