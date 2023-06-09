class Solution {
public:
    
    string longestPalindrome(string s) {
        int n = s.size(),start = 0,maxLen=1;
        string result;

        bool dp[n][n];
        memset(dp,0,sizeof dp);

        /**
        All single digit letters are palin
        */
        for(int i=0;i<n;i++){
            dp[i][i] = true;
        }

        // for size 2
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1] = true;
                start = i;
                maxLen = 2;
            }
        }
        for(int k = 3;k<=n;k++){
            // size of palin will start from n-3 to 3
            for(int i= 0;i<n-k+1;i++){
                int j = i+k-1;

                // it will check ith and jth string
                if(dp[i+1][j-1] && s[i]==s[j]){
                    dp[i][j] = true;

                    if(k>maxLen){
                        start = i;
                        maxLen = k;
                    }
                }
                   
            }
        }
        return  s.substr(start,maxLen);
    }
};