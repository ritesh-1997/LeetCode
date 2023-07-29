/**
 * Given two strings s and t of lengths m and n respectively, return the minimum window
 * substring of s such that every character in t (including duplicates) is included in
 * the window.
 *
 * If there is no such substring, return the empty string "".
 *
 * The testcases will be generated such that the answer is unique.
 *
 * Input: s = "ADOBECODEBANC", t = "ABC"
 * Output: "BANC"
 *
 * Input: s = "a", t = "aa"
 * Output: ""
 */
class Solution
{
public:
    string minWindow(string s, string t)
    {
        map<char, int> mp_s, mp_ta;
        int sSize = s.size(), tSize = t.size();
        if (tSize > sSize)
        {
            return "";
        }
        for (auto i : t)
        {
            mp_ta[i]++;
        }
        int cnt = 0, start = 0, start_ind = -1, min_len = INT_MAX;
        for (int i = 0; i < sSize; i++)
        {
            mp_s[s[i]]++;
            if (mp_s[s[i]] <= mp_ta[s[i]])
            {
                cnt++;
            }
            if (cnt == tSize)
            {
                while (mp_s[s[start]] > mp_ta[s[start]])
                {
                    // increment windown size and decrement mp[s[start]]
                    // as we not considering
                    mp_s[s[start++]]--;
                }
                if (min_len > i - start + 1)
                {
                    min_len = i - start + 1;
                    start_ind = start;
                }
            }
        }
        if (start_ind == -1)
            return "";
        return s.substr(start_ind, min_len);
    }
};