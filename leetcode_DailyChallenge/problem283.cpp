#include<iostream>
#include<vector>
using namespace std;
void moveZeros(vector<int>& arr){
    int n = arr.size();
    for(int i=0; i< n; i++){
        if(arr[i] == 0){
            
            for(int j= i; j < n - 1; j++){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    vector<int> arr = {6,3,2,7,0,1,0};
    int n = arr.size();
    moveZeros(arr);
    for(int i=0; i< n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}