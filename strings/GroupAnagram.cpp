class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;

        map<string,vector<string>> mp;
        for(auto i:strs){
            auto org = i;
            sort(i.begin(),i.end());
            
            if(mp.find(i) == mp.end()){
                vector<string> v;
                mp[i] =  v;
                mp[i].push_back(org);
            }
            else{
                mp[i].push_back(org);
            }
            
        }

        for(auto i: mp){
            res.push_back(i.second);
        }
        return res;
    }
};