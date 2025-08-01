#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int i=0, j = 0;
        while(i < target.size() && j < arr.size()){
            if(target[i] == arr[j]) i++;
            j++;
        }
        
    }
};

int main()
{
    
    return 0;
}