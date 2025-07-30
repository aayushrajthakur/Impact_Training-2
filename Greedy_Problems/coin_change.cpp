#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

void coinChange(vector<int> &arr, int amount){
    int n = arr.size();
    int res = 0;

    sort(arr.begin(), arr.end());

    for(int i=n-1;i>= 0;i--){
        if(amount >= arr[i]){
            int coin = (amount/arr[i]);
            res += coin;

            amount -= (coin *arr[i]);
        }

        

        if(amount == 0){
            break;
        }
    }
    cout<<res;

    
}

int main()
{
    vector<int> arr = {10, 5,2,1};
    int amount = 39;
    coinChange(arr, amount);
    return 0;
}