class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0),dp1(n,0);
        if(n == 1){
            return nums[0];
        }
        if(n == 2){
            return max(nums[0],nums[1]);
        }
        // including house 0 and excluding house n-1
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);

        for(int i=2;i<n-1;i++){
            dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
        }

        // excluding house 0 and including house n-1
        dp1[0] = 0;
        dp1[1] = nums[1];
        for(int i=2;i<n;i++){
            dp1[i] = max(dp1[i-2]+nums[i],dp1[i-1]);
        }
        

        return max(dp[n-2],dp1[n-1]);
    }
};