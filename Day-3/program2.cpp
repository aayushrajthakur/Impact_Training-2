#include<iostream>
using namespace std;
//find the Second maximum element.
int main()
{
    int arr[] = {4,2,8,6,7,1};
    int size = 6;
    int p1 ,p2;
    p1 = p2 = arr[0];
    for(int i=0;i<size;i++){
        if( (arr[i] > p1)){
            p1 = arr[i];
            if(arr[i] < p2 && arr[i]> p1){
                p2 = arr[i];
            }
        }
    }
    cout<<p1<<p2;
    return 0;
}