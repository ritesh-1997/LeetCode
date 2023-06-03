/**
 *
 * Given an encoded string, return its decoded string.
 * The encoding rule is: k[encoded_string], where the encoded_string
 *  inside the square brackets is being repeated exactly k times.
 * Note that k is guaranteed to be a positive integer.
 *
 * You may assume that the input string is always valid;
 * there are no extra white spaces, square brackets are well-formed, etc.
 * Furthermore, you may assume that the original data does not contain
 * any digits and that digits are only for those repeat numbers, k.
 * For example, there will not be input like 3a or 2[4].
 *
 * The test cases are generated so that the length of the output will never exceed 105.
 */

class Solution
{
public:
    string decodeString(string s)
    {
        /**
         * insert char into stack
         * we dont need to put '[' into stack just num and char
         * idea is each string to be repeated will be preceded by int
         * go till last num when we find ']' and store it into res string;
         */
        string res = "";
        stack<char> st;
        for (auto i : s)
        {

            if (i == ']')
            {
                string mid = "", number = "";

                int rep = 0, flag = 0;

                while (st.top() != '[')
                {
                    char top = st.top();
                    mid = top + mid;
                    st.pop();
                }

                // for removing '['
                st.pop();
                while (!st.empty() && isdigit(st.top()))
                {
                    number = st.top() + number;
                    st.pop();
                }
                int k = stoi(number);
                while (k--)
                {
                    for (auto j : mid)
                    {
                        st.push(j);
                    }
                }
            }
            else
            {
                st.push(i);
            }
        }

        while (!st.empty())
        {
            res = st.top() + res;
            st.pop();
        }

        return res;
    }
};