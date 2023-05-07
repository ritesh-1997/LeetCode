/**
 * SOrt the input array
 * take 3 pointers
 * one at i, next at i+1, last at n-1
 * and find the sum 
 * 
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int,int> mp;
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        set<vector<int>> st;
        for(int i=0;i<n-1;i++){
            int l = i+1,r=n-1;
            int x = nums[i];

            while(l<r){
                if((x+nums[l]+nums[r])== 0){
                    vector<int> v {x,nums[l],nums[r]};
                    sort(v.begin(),v.end());
                    st.insert(v);
                    l++;
                    r--;
                }
                else if((x+nums[l]+nums[r])< 0){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        for(auto i:st){
            res.push_back(i);
        }
        return res;
    }
};