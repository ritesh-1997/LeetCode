/**
 * You are given a 0-indexed circular string array words and a string target. 
 * A circular array means that the array's end connects to the array's
 * beginning.
 * 
 * Formally, the next element of words[i] is words[(i + 1) % n] and
 * the previous element of words[i] is words[(i - 1 + n) % n], where n is the 
 * length of words. 
 * 
 * Starting from startIndex, you can move to either the next
 * word or the previous word with 1 step at a time. 
 * 
 * Return the shortest distance 
 * needed to reach the string target. If the string target does not exist in words, return -1.
*/

class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
       
       int len = words.size(),ans =INT_MAX;
       for(int i = 0;i<len;i++){
           if(words[i]==target){
               int res = abs(startIndex-i);
               ans = min({ans,len-res,res});
           }
       }
       return ans == INT_MAX ? -1: ans;

    }
};