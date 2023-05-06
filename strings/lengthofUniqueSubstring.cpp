class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int size = s.length();
        int i = 0,j=0,res = 0;
        while(i<size && j<size){
            // if not there in set, then insert into set 
            if(st.find(s[j])==st.end()){
                st.insert(s[j++]);
                res = max(res,j-i);
            }
            //this will calculate length of unique.
            else{
                st.erase(s[i++]);
            }
        }
        return res;

    }
};