/**
 * Given an array of integers heights representing the histogram's bar height
 * where the width of each bar is 1, return the area of the largest rectangle
 * in the histogram.
 */

class Solution
{
public:
    vector<int> NSL(vector<int> &height, int n)
    {
        stack<int> st;
        vector<int> res;
        for (auto i = 0; i < n; i++)
        {
            while (!st.empty() && height[st.top()] >= height[i])
            {
                st.pop();
            }
            if (st.size() == 0)
            {
                res.push_back(-1);
            }
            else
            {
                res.push_back(st.top());
            }
            st.push(i);
        }
        return res;
    }

    vector<int> NSR(vector<int> &height, int n)
    {
        stack<int> st;
        vector<int> res;
        for (auto i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && height[st.top()] >= height[i])
            {
                st.pop();
            }
            if (st.size() == 0)
            {
                res.push_back(n);
            }
            else
            {
                res.push_back(st.top());
            }
            st.push(i);
        }
        reverse(res.begin(), res.end());
        return res;
    }

    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        auto left = NSL(heights, n);
        auto right = NSR(heights, n);
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int width = right[i] - left[i] - 1;
            int area = heights[i] * width;
            res = max(res, area);
        }

        return res;
    }
};