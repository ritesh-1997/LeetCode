class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0,end = nums.size()-1;
        int mid = 0;
        while(start<end){

            // Base Condition : 1st element is less than last 
            if(nums[start]<nums[end]){
                return nums[start];
            }

            mid = start + (end-start)/2;

            if(nums[start]<=nums[mid]){
                if(nums[mid]>nums[mid+1]){
                    return nums[mid+1];
                }
                start = mid+1;
            }
            else{
                if(nums[mid]<nums[mid-1]){
                    return nums[mid];
                }
                end = mid;
            }
        }
        return nums[start];
    }
};