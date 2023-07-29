/**
 * Given an integer array nums, return the length of the longest strictly increasing
 * subsequence
 *
 * Input: nums = [10,9,2,5,3,7,101,18]
 * Output: 4
 */
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size(), res = 1;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
                res = max(dp[i], res);
            }
        }
        return res;
    }
};