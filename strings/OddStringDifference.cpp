/**
 * You are given an array of equal-length strings words. 
 * Assume that the length of each string is n.
 * 
 * Each string words[i] can be converted into a difference 
 * integer array difference[i] of length n - 1 where 
 * difference[i][j] = words[i][j+1] - words[i][j] where 
 * 0 <= j <= n - 2. Note that the difference between two letters 
 * is the difference between their positions in the alphabet i.e. 
 * the position of 'a' is 0, 'b' is 1, and 'z' is 25.
 * 
 * For example, for the string "acb", the difference integer array 
 * is [2 - 0, 1 - 2] = [2, -1].
 * All the strings in words have the same difference integer array,
 * except one. You should find that string.
 * 
 * Return the string in words that has different difference integer array.
*/


class Solution {
public:
    string oddString(vector<string>& words) {
        int n = words.size(),len = words[0].size();
        map<vector<int>,vector<string>> mp;
        for(auto word:words){
            vector<int> v;
            for(int j=0;j<=len-2;j++){
                v.push_back(word[j+1] - word[j]);

            }
            mp[v].push_back(word);
            //cout<<word<<" : "<<v.size()<<" ; ";
        }
        vector<int> vt{0,0};
        //cout<<mp[vt].size();
        for(auto i:mp){
            if(i.second.size()==1){
                return i.second[0];
                break;
            }
        }
        return "";
    }
};