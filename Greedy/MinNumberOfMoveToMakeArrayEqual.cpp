/**
 * Given an integer array nums of size n, return the minimum number
 * of moves required to make all array elements equal.
 *
 * In one move, you can increment n - 1 elements of the array by 1.
 */
class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        int mn = INT_MAX;
        for (int n : nums)
        {
            mn = min(mn, n);
        }
        int res = 0;
        for (int n : nums)
        {
            res += (n - mn);
        }
        return res;
    }
};