class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1 || n== 3 ){
            return true;
        }
        if(n%3!=0 || n<3)
            return false;
        return isPowerOfThree(n/3);
    }
};


class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1)
            return true;
        for(int i=1;pow(3,i)<=n;i++){
            if(pow(3,i)==n){
                return true;
            }
        }
        return false;
        
    }
};