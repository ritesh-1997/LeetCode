/**
 * Given a string s and a dictionary of strings wordDict, 
 * return true if s can be segmented into a space-separated 
 * sequence of one or more dictionary words.
 * 
 * Note that the same word in the dictionary may be reused multiple 
 * times in the segmentation. 
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string,int> mp;

        for(auto i:wordDict){
            mp[i]++;
        }
        int start = 0,n=s.size();
        vector<bool> dp(n+1,false);
        dp[n] = true;
        for(int i=n-1;i>=0;i--){
            string sub = "";
            for(int j=i;j<n;j++){
                sub+=s[j];
                if(mp.find(sub)!=mp.end()){
                    //cout<<sub<<" ";
                    if(dp[j+1]){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[0];
    }
};