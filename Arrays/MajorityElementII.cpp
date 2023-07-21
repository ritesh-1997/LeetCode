/**
 * Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
 */
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int countMaj = nums.size() / 3;
        map<int, int> mp;
        vector<int> res;
        for (auto num : nums)
        {
            mp[num]++;
        }
        for (auto i : mp)
        {
            if (i.second > countMaj)
            {
                res.push_back(i.first);
            }
        }
        return res;
    }
};