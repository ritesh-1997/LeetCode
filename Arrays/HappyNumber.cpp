/**
 * 
 * Write an algorithm to determine if a number n is happy.
 * A happy number is a number defined by the following process:
 * Starting with any positive integer, replace the number by the sum of the squares of its digits.
 * Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
 * Those numbers for which this process ends in 1 are happy.
 * Return true if n is a happy number, and false if not.
 * 
 * if num is 1 or 7 then only value will be 1 otherwise it won't.
 * also consider only if generated 'n' is more than 9.
 * 
*/


class Solution {
public:
    bool isHappy(int n) {

        int flag = 0;
        if(n==1||n==7){
            flag = 1;
        }
        while(n>9){
            int sum = n,val = 0;
            while(sum){
                int rem = sum%10;
                val += rem*rem;
                sum /=10;
            }
            n=val;
            if(n==1||n==7){
                flag = 1;
                break;
            }
        }
        if(flag==1){
            return true;
        }
        else
            return false;   
    }
};