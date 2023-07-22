/**https://leetcode.com/problems/maximum-product-subarray/
 *
 * Given an integer array nums, find a  subarray
 * that has the largest product, and return the product.
 *
 * The test cases are generated so that the answer will fit in a 32-bit integer.
 */
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int max_prod = nums[0], min_prod = nums[0], res = nums[0];
        int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }
        for (auto i = 1; i < n; i++)
        {
            int temp = max_prod;
            max_prod = max({max_prod * nums[i], nums[i], min_prod * nums[i]});
            min_prod = min({min_prod * nums[i], nums[i], temp * nums[i]});

            res = max(res, max_prod);
        }
        return res;
    }
};