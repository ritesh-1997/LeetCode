/**
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 */
class Solution
{
public:
    void backtrack(string op, vector<string> &res, int open, int close)
    {
        if (open == 0 && close == 0)
        {
            res.push_back(op);
            return;
        }
        if (open == close)
        {
            string op1 = op;
            op1.push_back('(');
            backtrack(op1, res, open - 1, close);
        }
        else if (open == 0)
        {
            string op1 = op;
            op1.push_back(')');
            backtrack(op1, res, open, close - 1);
        }
        else if (close == 0)
        {
            string op1 = op;
            op1.push_back('(');
            backtrack(op1, res, open - 1, close);
        }
        else
        {
            string op1 = op;
            string op2 = op;
            op1.push_back('(');
            op2.push_back(')');

            backtrack(op1, res, open - 1, close);
            backtrack(op2, res, open, close - 1);
        }
    }
    vector<string> generateParenthesis(int n)
    {
        int open = n;
        int close = n;
        vector<string> res;
        string op = "";
        backtrack(op, res, open, close);
        return res;
    }
};