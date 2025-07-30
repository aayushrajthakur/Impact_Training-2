#include<iostream>
using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while(word.length() <= k){
            for(int i=0; i< word.length(); i++){
                word += (word[i]+ 1);
            }
        }

        return word[k-1];
    }
};


int main()
{
    Solution soln;
    cout<< soln.kthCharacter(5);
    return 0;
}