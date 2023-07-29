/**
 * Given an array of strings strs, group the anagrams together.
 * You can return the answer in any order.
 *
 * An Anagram is a word or phrase formed by rearranging the letters
 * of a different word or phrase, typically using all the original
 * letters exactly once.
 */
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> res;

        map<string, vector<string>> mp;
        for (auto i : strs)
        {
            auto org = i;
            sort(i.begin(), i.end());
            mp[i].push_back(org);
        }

        for (auto i : mp)
        {
            res.push_back(i.second);
        }
        return res;
    }
};