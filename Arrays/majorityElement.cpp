class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // map<int,int> mp;
        // for(auto i:nums)
        //     mp[i]++;
        // for(auto i:mp)
        //     if(i.second>floor(nums.size()/2))
        //         return i.first;
        // return -1;
        
        int maj = 0,count=1;
        
        for(int i=0;i<nums.size();i++){
            if(nums[maj]==nums[i]){
                count++;
            }
            else{
                count--;
            }
            if(count==0){
                maj = i;
                count =1;
            }
        }
        return nums[maj];
    }
};