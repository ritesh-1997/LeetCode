/**
 * Given an array of integers citations where citations[i] is the number
 * of citations a researcher received for their ith paper, return the
 * researcher's h-index.
 *
 * According to the definition of h-index on Wikipedia: The h-index is defined
 * as the maximum value of h such that the given researcher has published at
 * least h papers that have each been cited at least h times.
 *
 */
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        sort(citations.begin(), citations.end());
        int res = 0, n = citations.size();
        if (n == 1 && citations[0] > 0)
        {
            return 1;
        }
        for (int i = 0; i < n; i++)
        {
            if (citations[i] >= n - i)
                res = max(res, n - i);
            else
                res = citations[i];
        }
        return res;
    }
};