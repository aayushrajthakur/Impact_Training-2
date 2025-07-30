#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Item{
    int profit;
    int weight;
    double ratio;
};

bool compareItems(const Item &a, const Item &b){
    return a.ratio<b.ratio;
}

int knapsack(vector<Item>& items, int cap){
    int n = items.size();
    sort(items.begin(), items.end(), compareItems);
    int res = 0;
    for(int i=n-1; i>= 0; i--){
        cout<<items[i].ratio<<endl;
        if(cap >= items[i].weight){
            cap -= items[i].weight;
            res += items[i].profit;
        }else if(cap < items[i].weight){
            res += (cap * items[i].profit) / items[i].weight;
        }
        if(cap == 0){
            break;
        }
    }
    return res;
    
}

int main()
{
    int m;
    cin>>m;
    vector<Item> items(m);
    for(int i=0;i<m;i++){
        cin>>items[i].profit>> items[i].weight;
        items[i].ratio = (items[i].profit/ items[i].weight);
    }
    int capacity;
    cin>>capacity;
    int res = knapsack(items, capacity);
    cout<<"The total profit is : "<<res;
    return 0;
}