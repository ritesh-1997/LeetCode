class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int dp[n],res = 1;
        memset(dp,1,sizeof(dp));

        for(int i=0;i<n;i++){
            dp[i] = 1;
            for(int j = 0;j<=i;j++){
                if(nums[i]>nums[j])
                dp[i] = max(dp[i],dp[j]+1);
                res = max(res,dp[i]);
            }
        }
        return res;
    }
};