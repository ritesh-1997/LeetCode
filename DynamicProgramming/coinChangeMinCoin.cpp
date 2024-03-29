/**
 * You are given an integer array coins representing coins of different
 * denominations and an integer amount representing a total amount of money.
 *
 * Return the fewest number of coins that you need to make up that amount.
 * If that amount of money cannot be made up by any combination of the coins,
 * return -1.
 *
 * You may assume that you have an infinite number of each kind of coin.
 */
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, INT_MAX - 1000);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            dp[i] = INT_MAX;

            for (auto coin : coins)
            {
                // if coin value is greater that current amount
                if (i - coin < 0)
                    break;
                if (dp[i - coin] != INT_MAX)
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};