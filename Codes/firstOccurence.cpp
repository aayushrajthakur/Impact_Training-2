#include<iostream>
using namespace std;
int findFirstOccurence(string sbig, string small){
    int n = sbig.length();
    int m = small.length();
    for(int i=0;i<=n-m;i++){
        int j = 0;
        while (j < m && sbig[i + j] == small[j]) {
            j++;
        }
        if(j == m){
            return i;
        }
    }
    return -1;
}
int main()
{
    string sbig, small;
    cin>>sbig;
    cin>>small;
    int k = findFirstOccurence(sbig, small);
    cout<<k;
    return 0;
}