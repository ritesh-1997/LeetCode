/**
 * You have two types of tiles: a 2 x 1 domino shape and a tromino shape.
 * You may rotate these shapes.
 *
 * Given an integer n, return the number of ways to tile an 2 x n board.
 * Since the answer may be very large, return it modulo 109 + 7.
 *
 *
 * In a tiling, every square must be covered by a tile. Two tilings are
 * different if and only if there are two 4-directionally adjacent cells
 * on the board such that exactly one of the tilings has both squares occupied
 * by a tile.
 */

class Solution
{
public:
    int numTilings(int n)
    {
        long long mod = 1e9 + 7;
        vector<long long> dp(1001, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        if (n <= 3)
        {
            return dp[n];
        }
        for (auto i = 4; i <= n; i++)
        {
            dp[i] = (2 * dp[i - 1] + dp[i - 3]) % mod;
        }
        return dp[n] % mod;
    }
};