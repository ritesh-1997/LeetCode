/**
 * find the target-nums[i] if found then return i,target-nums[i] index
 * insert nums[i] and index
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            int val = target-nums[i];
            if(mp.find(val)!=mp.end()){
                res.push_back(mp[val]);
                res.push_back(i);
                return res; 
            }
            mp[nums[i]] = i;
        }

        return res;
    }
};