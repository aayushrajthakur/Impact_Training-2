#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findSubArray(vector<int> arr, int k){
    int n = arr.size();
    vector<vector<int>> result;

    sort(arr.begin(), arr.end());

    for(int i=0; i< n; i += 3){
        if(i+ 2 < n && arr[i + 2] - arr[i] > k){
            return {};
        }
        result.push_back({arr[i], arr[i + 1], arr[i + 2]});
    }
    return result;
}

int main()
{
    int m, k;
    cin>>m;
    vector<int> arr(m);
    for(int i=0;i<m; i++){
        cin>>arr[i];
    }

    cin>>k;
    vector<vector<int>> res = findSubArray(arr, k);
    if(res.empty()){
        cout<<"{}"<<endl;
        return 0;
    }
    cout<<"[";
    for(int i=0; i< res.size(); i++){
        cout<<"[";
        for(int j=0; j< res[0].size(); j++){
            cout<<res[i][j];
            if(j != res[0].size() - 1){
                cout<<", ";
            }
        }
        cout<<"]";
        if(i != res.size() - 1){
            cout<<",";
        }
        
    }
    cout<<"]";
    return 0;
}