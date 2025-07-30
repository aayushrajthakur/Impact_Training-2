#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

void countFrequency(const vector<int>& nums){
    int n = nums.size();
    unordered_map<int, int> freq;

    for(int num : nums){
        freq[num]++;
    }

    for(auto& pair : freq){
        cout<<pair.first<<" : "<<pair.second<<endl;
    }

}
int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    countFrequency(arr);
    return 0;
}