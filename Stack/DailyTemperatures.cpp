/**
 * Given an array of integers temperatures represents the daily temperatures,
 * return an array answer such that answer[i] is the number of days you have
 * to wait after the ith day to get a warmer temperature. If there is no future
 * day for which this is possible, keep answer[i] == 0 instead.
 */

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> res;
        stack<int> st;
        for (auto i = n - 1; i >= 0; i--)
        {
            // pop only is stack top is smaller than current element
            // so it maintains increasing order
            while (!st.empty() && temperatures[st.top()] <= temperatures[i])
            {
                // cout<<i<<" "<<temperatures[st.top()]<<" "<<st.top()<<endl;
                st.pop();
            }
            if (st.size() == 0)
                res.push_back(0);
            else
                res.push_back(st.top() - i);
            st.push(i);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};