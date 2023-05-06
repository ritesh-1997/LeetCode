class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        for(auto i:nums1){
            mp[i]++;
        }
        vector<int> res;
        for(auto i:nums2){
            if(mp.find(i)!=mp.end() && mp[i]>0){
                mp[i]--;
                res.push_back(i);
            }
        }
        return res;
    }
};