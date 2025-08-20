#include<iostream>
#include<vector>
using namespace std;

int countZeros(vector<int>& nums){
    int zeros = 0;
    int count = 0;
    for(int i=0; i< nums.size(); i++){
        if(nums[i] == 0){
            zeros++;
            count += zeros;
        }else {
            zeros = 0;
        }
    }
    return count;
}

int main()
{
    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    cout<<countZeros(nums)<<endl;
    return 0;
}