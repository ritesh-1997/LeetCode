class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        int dp[amount+1];
        memset(dp,INT_MAX,sizeof dp);

        dp[0] = 0;

        for(int i=1;i<=amount;i++){
            dp[i] = INT_MAX;
            for(auto coin : coins){
                // if value is more than current sum
                if(i-coin<0)
                    break;
                // Some value is there apart from INT_MAX
                // we will start from 0 then add 1
                if(dp[i-coin]!=INT_MAX){
                    dp[i] = min(dp[i],1+dp[i-coin]);
                }
            }
        }
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};