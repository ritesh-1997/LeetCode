/**
 * Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
 *
 * You may return the answer in any order.
 */
class Solution
{
public:
    void util(vector<vector<int>> &res, vector<int> &st, int l, int n, int k)
    {
        if (st.size() == k)
        {
            res.push_back(st);
            return;
        }
        if (k > n)
        {
            return;
        }
        for (int i = l; i <= n; i++)
        {
            st.push_back(i);
            util(res, st, i + 1, n, k);
            st.pop_back();
        }
    }
    vector<vector<int>> solve(int n, int k)
    {
        vector<vector<int>> res;
        vector<int> st;
        util(res, st, 1, n, k);
        return res;
    }
    vector<vector<int>> combine(int n, int k)
    {
        return solve(n, k);
    }
};