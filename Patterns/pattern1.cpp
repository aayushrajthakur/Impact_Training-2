#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int>& arr){
    int n = arr.size();
    int key, i, j;
    for(i=1; i< n; i++){
        key = arr[i];
        j = i-1;

        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
    return;
}


void print(vector<int>& arr){
    int n = arr.size();
    for(int i=0; i<n ; i++){
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int m;
    cin>>m;

    vector<int> arr(m);
    for(int i=0; i<m; i++){
        cin>>arr[i];
    }
    cout<<"Array before sorting : ";
    print(arr);
    insertionSort(arr);
    cout<<"\nArray after sorting : ";

    print(arr);
    return 0;
}