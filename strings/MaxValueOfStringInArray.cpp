/**
 * The value of an alphanumeric string can be defined as:
 * 
 * The numeric representation of the string in base 10, 
 * if it comprises of digits only.
 * 
 * The length of the string, otherwise.
 * 
 * Given an array strs of alphanumeric strings, return the 
 * maximum value of any string in strs.
*/

class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int res = 0;
        for(auto i:strs){
            int f = 0;
            for(auto j:i){
                if(j>=97&&j<=122){
                    // alphanumeric
                    f = 1;
                }
            }
            if(f){
                res = max(res,int(i.size()));
            }
            else{
                res = max(res,stoi(i));
            }
        }
        return res;
    }
};