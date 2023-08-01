class Solution
{
public:
    void solve(vector<vector<int>> &res, vector<int> &st, vector<int> &candidates, int l, int sum, int target, int n)
    {
        if (sum == target)
        {
            res.push_back(st);
            return;
        }
        if (sum > target)
        {
            return;
        }
        for (int i = l; i < n; i++)
        {
            st.push_back(candidates[i]);
            solve(res, st, candidates, i, sum + candidates[i], target, n);
            st.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> st;
        int n = candidates.size();
        solve(res, st, candidates, 0, 0, target, n);
        return res;
    }
};