#include<bits/stdc++.h>

using namespace std;

int main()
{
    int m;
    cin>>m;


    map<int, string> dict;
    for (int i = 0; i<m; i++) {
        int id;
        string name;

        cin>>name>>id;
        dict[id] = name;
    }

    int i=0;

    

    cout<<"Student list in reverse order:\n";
    for(auto it = dict.rbegin(); it != dict.rend(); it++){
        if(i== 3) break;
        cout<<it->second<<" : "<<it->first<<endl;
        i++;
    }
    return 0;
}