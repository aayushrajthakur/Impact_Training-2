#include<iostream>
#include<vector>
using namespace std;

int maxSum(vector<int>& arr, int m){
    int maxsum = arr[0], currentMax = arr[0];

    for(int num : arr){
        currentMax = max(currentMax + num, num);
        maxsum = max(maxsum, currentMax);
    }

    return maxsum;
}

int main()
{
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};

    cout<<maxSum(arr, 7);
    return 0;
}