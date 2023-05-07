/**
 * You are given a binary string s consisting only of zeroes and ones.
 * A substring of s is considered balanced if all zeroes are before ones
 *  and the number of zeroes is equal to the number of ones inside the 
 * substring. Notice that the empty substring is considered a balanced 
 * substring.
 * 
 * Return the length of the longest balanced substring of s.
 * 
 * A substring is a contiguous sequence of characters within a string.
 * 
 * */

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int maxi = 0;
        for (int i = 0; i < s.size();) {
            int zeros = 0;
            int ones = 0;
            while (i < s.size() and s[i] == '0') {
                zeros++;
                i++;
            }
            while (i < s.size() and s[i] == '1') {
                ones++;
                i++;
            }
            int len = 2 * min(zeros, ones);
            maxi = max(maxi, len);
        }
        return maxi;
    }
};



class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {

        int n = s.size();
        int cntZero = 0,cntOne = 0, res = 0;
        for(int i=0;i<n;i++){
            int j = i;
            while(j<n){
                if(s[j]=='0'){
                    cntZero++;
                }
                else
                    break;
                j++;
            }
            while(j<n){
                if(s[j]=='1'){
                    cntOne++;
                }
                else
                    break;
                j++;
                if(cntZero==cntOne){
                    res = max(res,j-i);
                }
            }
            cntOne = cntZero = 0;
        }

        return res;
        
    }
};