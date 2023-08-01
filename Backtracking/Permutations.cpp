/**
 * Given an array nums of distinct integers, return all the possible permutations.
 * You can return the answer in any order.
 */
class Solution
{
public:
    void solve(vector<vector<int>> &res, vector<int> nums, int l, int n)
    {
        if (l == n)
        {
            res.push_back(nums);
            return;
        }

        for (int i = l; i < n; i++)
        {
            swap(nums[i], nums[l]);
            solve(res, nums, l + 1, n);
            swap(nums[l], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> st;
        int n = nums.size();
        solve(res, nums, 0, n);
        return res;
    }
};