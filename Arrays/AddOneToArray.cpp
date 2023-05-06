/**
 * Input: digits = [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * Incrementing by one gives 123 + 1 = 124.
 * Thus, the result should be [1,2,4].
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sum = 0,rem = 1;
        vector<int> res;

        for(int i = digits.size()-1 ; i>=0 ; i--){
            int val = digits[i] +rem;
            
            if(val == 10){
                res.push_back(0);
                rem = 1;
            }
            else{
                res.push_back(val);
                rem=0;
            }
        }
        if(rem == 1){
            res.push_back(1);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};