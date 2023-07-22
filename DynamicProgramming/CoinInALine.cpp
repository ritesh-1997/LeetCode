/**
 * https://www.interviewbit.com/problems/coins-in-a-line/
 *
 * There are A coins (Assume A is even) in a line.
 *
 * Two players take turns to take a coin from one of the ends of the line until there are no more coins left.
 *
 * The player with the larger amount of money wins, Assume that you go first.
 *
 * Return the maximum amount of money you can win.
 *
 * NOTE:
 *
 * You can assume that opponent is clever and plays optimally.
 */
int solve(vector<int> A, int i, int j, vector<vector<int>> &dp)
{
    if (i > j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    // taking element from one end
    // other will either take from left end or right end and we will inc our left end
    int opt1 = A[i] + min(solve(A, i + 2, j, dp), solve(A, i + 1, j - 1, dp));

    // our is right end
    // opponet will take either from left or right and we take min to maxi ours
    int opt2 = A[j] + min(solve(A, i + 1, j - 1, dp), solve(A, i, j - 2, dp));

    return dp[i][j] = max(opt1, opt2);
}
int Solution::maxcoin(vector<int> &A)
{
    int n = A.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(A, 0, n - 1, dp);
}
