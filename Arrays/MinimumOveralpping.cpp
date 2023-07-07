/**
 * Given an array of intervals intervals where intervals[i] = [starti, endi],
 *  return the minimum number of intervals you need to remove to make the rest
 * of the intervals non-overlapping.
 */

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int cnt = 0, n = intervals.size();
        sort(intervals.begin(), intervals.end());
        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] < intervals[i - 1][1])
            {
                cnt++;
                intervals[i][1] = min(intervals[i - 1][1], intervals[i][1]);
            }
        }
        return cnt;
    }
};