/**
 * 
 * You are given a 0-indexed string array words.
 * 
 * Two strings are similar if they consist of the same characters.
 * 
 * For example, "abca" and "cba" are similar since both consist of 
 * characters 'a', 'b', and 'c'.
 * 
 * However, "abacba" and "bcfd" are not similar since they do not 
 * consist of the same characters.
 * 
 * Return the number of pairs (i, j) such that 0 <= i < j <= word.length - 1
 * and the two strings words[i] and words[j] are similar.
*/

class Solution {
public:
    int similarPairs(vector<string>& words) {
        map<string,int> mp;
        for(auto i:words){
            set<char> st(i.begin(),i.end());
            string t(st.begin(),st.end());
            sort(t.begin(),t.end());
            mp[t]++;
        }

        int res = 0;

        for(auto i:mp){
            int r = i.second;
            res+=(r*(r-1))/2;
        }

       
        return res;
    }
};