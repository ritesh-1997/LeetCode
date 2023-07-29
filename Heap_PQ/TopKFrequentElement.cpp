/**
 * Given an integer array nums and an integer k, return the k
 * most frequent elements. You may return the answer in any order.
 */
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>> pq;
        vector<int> res;
        map<int, int> mp;
        for (auto i : nums)
        {
            mp[i]++;
        }
        for (auto i : mp)
        {
            pq.push({i.second, i.first});
        }
        while (k--)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};