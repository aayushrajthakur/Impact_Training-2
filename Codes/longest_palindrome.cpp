//Maximum substring using dynamic programming 


#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    int m = s1.length();
    int n = s2.length();

    reverse(s2.begin(), s2.end());

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    int max = INT_MIN;
    int l1 = 0, l2 = 0;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                if(dp[i][j]> max){
                    l1 = i;
                    l2 = j;
                    max = dp[i][j];
                }
            }
        }
    }

    string res = "";
    while(dp[l1][l2] != 0){
        res =  s1[l1-1]+res;
        l1--;
        l2--;
    }

    cout<<res<<endl;
    cout<<"Longest Palindrome : "<<max;

    return 0;
}