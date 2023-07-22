/**
 * Given a circular integer array nums of length n,
 * return the maximum possible sum of a non-empty subarray of nums.
 *
 * A circular array means the end of the array connects to the beginning
 * of the array. Formally, the next element of nums[i] is nums[(i + 1) % n]
 * and the previous element of nums[i] is nums[(i - 1 + n) % n].
 *
 * A subarray may only include each element of the fixed buffer nums at most once.
 * Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist
 *
 * i <= k1, k2 <= j with k1 % n == k2 % n.
 */

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int mx = INT_MIN, curr = 0, mn = INT_MAX, curr1 = 0, curr2 = 0;
        for (auto i : nums)
        {
            curr += i;
            curr1 += i;
            curr2 += i;
            mx = max(mx, curr1);
            if (curr1 < 0)
                curr1 = 0;
            mn = min(mn, curr2);
            if (curr2 > 0)
                curr2 = 0;
        }
        return (curr == mn) ? mx : max(mx, curr - mn);
    }
};