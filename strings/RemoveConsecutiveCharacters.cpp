/**
 * Given a string A and integer B, remove all consecutive same characters that have length exactly B.
 *
 * NOTE : All the consecutive same characters that have length exactly B will be removed simultaneously.
 */
string Solution::solve(string A, int B)
{
    string s = "", tmp = "";
    int c = 0;
    int j = 0;
    int i = 0;
    while (i < A.size())
    {
        j = i;
        while (A[j] == A[i] && j < A.size())
        {
            tmp += A[j++];
        }
        if (j - i != B)
        {
            s += tmp;
        }
        i = j;
        tmp = "";
    }
    return s;
}
