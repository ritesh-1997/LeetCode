#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome( string s){
        int i=0,j=s.size()-1;

        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int countSubstrings(string s) {
        int res = 0;
        for(int i=0;i<s.size();i++){
            string str = "";
            for(int j=i;j<s.size();j++){
                str +=s[j];
                auto ispalin = isPalindrome(str);
                if(ispalin){
                    res++;
                }
            }
        }
        return res;
    }
};