/**
 * Given a string containing digits from 2-9 inclusive,
 * return all possible letter combinations that the number
 * could represent. Return the answer in any order.
 *
 * A mapping of digits to letters (just like on the telephone buttons)
 * is given below. Note that 1 does not map to any letters.
 */

class Solution
{
public:
    int n;
    vector<string> ans;
    vector<string> a = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void solve(int i, string &digits, string &s)
    {
        if (i == n)
        {
            ans.push_back(s);
            return;
        }
        int digit = digits[i] - '0';
        for (char ch : a[digit])
        {
            s.push_back(ch);
            solve(i + 1, digits, s);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return ans;
        n = digits.size();
        string s;
        solve(0, digits, s);
        return ans;
    }
};