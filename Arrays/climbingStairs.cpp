/**
 * write few example and find the pattern
 * We will reach to fibbonaci series.
 * 
*/

class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1,res = 0;
        if(n<=2){
            return n;
        }
        else{
            res = a + b;
            for(int i = 3;i<=n;i++){
                a = b;
                b = res;
                res = a+b;
            }
        }
        return res;

    }
};