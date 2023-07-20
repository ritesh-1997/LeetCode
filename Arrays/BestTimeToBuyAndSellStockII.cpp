/**
 * You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
 *
 * On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the
 * stock at any time. However, you can buy it then immediately sell it on the same day.
 *
 * Find and return the maximum profit you can achieve.
 */

class Solution
{
public:
    int maxProfit(vector<int> &nums)
    {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] < nums[i + 1])
            {
                res += (nums[i + 1] - nums[i]);
            }
        }
        return res;
    }
};