/**
 * Sol1: Sort and compare
 * Sol2: use hashing/map for one string 
 * and check other string in the the hash.
 * 
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return (s==t)?true:false;
    }
};