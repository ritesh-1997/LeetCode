/**
 * Given an array of intervals where intervals[i] = [starti, endi], merge all
 * overlapping intervals, and return an array of the non-overlapping intervals
 * that cover all the intervals in the input.
 */
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size(), j = 0;
        for (auto i : intervals)
        {
            cout << i[0] << " " << i[1] << endl;
        }
        for (auto i = 1; i < n; i++)
        {
            if (intervals[i][0] <= intervals[j][1])
            {
                intervals[j][0] = min(intervals[i][0], intervals[j][0]);
                intervals[j][1] = max(intervals[i][1], intervals[j][1]);
            }
            else
            {
                j++;
                intervals[j] = intervals[i];
            }
        }
        for (int i = 0; i <= j; i++)
        {
            res.push_back(intervals[i]);
        }
        return res;
    }
};