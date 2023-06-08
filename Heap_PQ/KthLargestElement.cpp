/**
 * Given an integer array nums and an integer k, return the kth largest element in the array.
 *
 * Note that it is the kth largest element in the sorted order, not the kth distinct element.
 *
 * You must solve it in O(n) time complexity.
 */

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // min will be at top
        priority_queue<int, vector<int>, greater<int>> pq;
        // insert top k element and max of those k will be at top
        for (auto i = 0; i < k; i++)
        {
            pq.push(nums[i]);
        }
        for (int i = k; i < nums.size(); i++)
        {
            // if nums is greater than min of all then pop min and push the val
            // it will automatically resuffle it.
            if (pq.top() < nums[i])
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};