/**
 * You are given two strings A and B.
 * Check whether there exists any permutation of both A and B such that they are equal.
 *
 * Return a single integer 1 if its exists, 0 otherwise.
 */
int Solution::permuteStrings(string A, string B)
{
    int n = A.size(), m = B.size();
    if (n != m)
    {
        return 0;
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    if (A == B)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
