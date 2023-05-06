class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size(),prod = 1;
        vector<int> prefix(n,1),suffix(n,1), res;

        
        for(int i = 1;i<n;i++){
            
            prefix[i] = prefix[i-1]*nums[i-1];
        }

        prod = 1;

        suffix[n-1] = prod;
        for(int i= n-1;i>0; i--){
            prod *= nums[i];
            suffix[i-1] = prod;
        }


        for(int i = 0; i<n;i++){
            res.push_back(prefix[i]*suffix[i]);
        }
        return res;
    }
}; 


// without extra space

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> out;
        int n=nums.size();
        // int out[n];
        long long leftres=nums[0],rightres=1;
        out.push_back(nums[0]);
        for(int i=1;i<n;i++){
            leftres *= nums[i];
            out.push_back(leftres);
            
        }
        out[n-1] = out[n-2];
        
        for(int i=n-2;i>=1;i--){
            rightres *= nums[i+1];
            out[i] = rightres*out[i-1];
        }
        out[0] = rightres*nums[1];
        return out;
    }
};