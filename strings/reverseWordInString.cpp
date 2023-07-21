/**
 * Given an input string s, reverse the order of the words.
 *
 * A word is defined as a sequence of non-space characters.
 * The words in s will be separated by at least one space.
 *
 * Return a string of the words in reverse order concatenated by a single space.
 *
 * Note that s may contain leading or trailing spaces or multiple spaces between two words.
 * The returned string should only have a single space separating the words. Do not include any extra spaces.
 *
 */
class Solution
{
public:
    string reverseWords(string s)
    {
        string res = "", ans = "";
        stack<string> st;
        for (auto i : s)
        {
            if (i == ' ')
            {
                if (res.size() > 0)
                {
                    st.push(res);
                }
                res = "";
                continue;
            }
            res += i;
        }
        if (res.size())
            st.push(res);
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
            ans += ' ';
        }
        return ans.substr(0, ans.size() - 1);
    }
};