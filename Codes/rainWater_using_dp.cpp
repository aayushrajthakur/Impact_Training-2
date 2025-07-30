#include <bits/stdc++.h>
using namespace std;

int maxWater(vector<int>& arr) {
    int n = arr.size();

    
    vector<int> left(n);

    
    vector<int> right(n);

    int water = 0;

    
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], arr[i]);

    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], arr[i]);

    
    for (int i = 0; i < n ; i++) {
        water += min(left[i], right[i]) - arr[i];
    }

    return water;
}

int main() {
    int m;
    cin>>m;

    vector<int> arr(m);
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    cout << maxWater(arr);
    return 0;
}