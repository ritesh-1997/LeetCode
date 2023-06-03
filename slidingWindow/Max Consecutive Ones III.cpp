/**
 *
 *
 * Given a binary array nums and an integer k, return the maximum number
 * of consecutive 1's in the array if you can flip at most k 0's.
 *
 * */

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        /**
         * Find kZero and length from init index.
         * and perform same with other index too
         * calc max size of window.
         */
        int j = 0, findZero = 0, n = nums.size(), res = 0;

        for (int i = 0; i < n; i++)
        {

            if (nums[i] == 0)
            {
                findZero++;
            }
            if (findZero > k)
            {
                while (nums[j] != 0)
                {
                    j++;
                }
                // for next location of zero
                j++;
                // once we found zero from start we decrement the count
                // of zero so that number of zero in window remains same
                findZero--;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};