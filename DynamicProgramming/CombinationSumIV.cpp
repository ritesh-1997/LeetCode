/**
 * 
 * Given an array of distinct integers nums and a target integer target, 
 * return the number of possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.


*/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unsigned int> res(target+1,0);
        res[0] = 1;

        for(int i=1;i<=target;i++){
            for(auto coin:nums){
                if(i>=coin)
                    res[i] +=res[i-coin];
            }
        }
        return res[target];
    }
};