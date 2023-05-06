class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos = 0, i = 0, size = nums.size(); 
        while(i<size){
            if(nums[i]==0){
                i++;
            }
            else{
                nums[pos++] = nums[i++];
            }
        }
        while(pos<size){
            nums[pos++] = 0;
        }
    }
};