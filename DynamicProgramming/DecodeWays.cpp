/**
 * A message containing letters from A-Z can be encoded into numbers using the following mapping:
 *
 * 'A' -> "1"
 * 'B' -> "2"
 * ...
 * 'Z' -> "26"
 *
 * To decode an encoded message, all the digits must be grouped then mapped back into letters
 * using the reverse of the mapping above (there may be multiple ways). For example, "11106"
 * can be mapped into:
 *
 * "AAJF" with the grouping (1 1 10 6)
 * "KJF" with the grouping (11 10 6)
 * Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6"
 * is different from "06".
 *
 * Given a string s containing only digits, return the number of ways to decode it.
 *
 * The test cases are generated so that the answer fits in a 32-bit integer.
 *
 */
class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.size();
        if (n == 1)
            return s[0] != '0';
        vector<int> dp(n);
        dp[n - 1] = (s[n - 1] != '0');
        if (s[n - 2] == '0')
            dp[n - 2] = 0;
        else
        {
            if (stoi(s.substr(n - 2, 2)) <= 26)
                dp[n - 2] = dp[n - 1] + 1;
            else
                dp[n - 2] = dp[n - 1];
        }
        for (int i = n - 3; i >= 0; i--)
        {
            if (s[i] == '0')
                dp[i] = 0;
            else if (stoi(s.substr(i, 2)) <= 26 && stoi(s.substr(i, 2)) >= 10)
                dp[i] = dp[i + 1] + dp[i + 2];
            else
                dp[i] = dp[i + 1];
        }
        return dp[0];
    }
};