/**
 * Given two strings needle and haystack, return the index
 * of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 */
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        set<string> st;
        int n = haystack.size(), t = needle.size();
        if (haystack == needle)
        {
            return 0;
        }
        for (int i = 0; i < n - t + 1; i++)
        {
            string res = haystack.substr(i, t);
            // cout<<res<<endl;
            if (res == needle)
                return i;
        }
        return -1;
    }
};