#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& arr, int low, int high, int key){
    
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == key){
            return mid;
        }else if(arr[mid] > key){
            low = mid + 1;

        }else{
            high = mid - 1;
        }
    }
    return -1;
    

}

int main()
{
    vector<int> arr = {4,5,6,7,0,1,2};
    int n = arr.size();
    int key = 0;
    cout << binarySearch(arr, 0, n, key);
    return 0;
}