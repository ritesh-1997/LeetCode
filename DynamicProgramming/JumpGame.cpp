class Solution {
public:
    bool canJump(vector<int>& nums) {
        int flag = 0;
        // checking if 0 is there in 
        // given array
        for(auto i:nums){
            if(i==0){
                flag = 1;
                break;
            }
        }
        
        if(flag==0){
            return true;
        }

        int rem = 0,n = nums.size();

        for(int i=0;i<nums.size();i++){
            rem = max(rem,nums[i]);
            // if we have reach 0 
            rem --;

            if(rem<0&&i!=n-1){
                return false;
            }
        }
        return true;
    }
};