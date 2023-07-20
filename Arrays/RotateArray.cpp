/**
 * Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
 */
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        // reverse 0 : (n-k)
        reverse(nums.begin(), nums.begin() + (nums.size() - k));
        // reverse the element from. k to last
        reverse(nums.begin() + (nums.size() - k), nums.end());
        // reverse
        reverse(nums.begin(), nums.end());
    }
};