class Solution {
public:
    int getSum(int a, int b) {
        // will be same as sum except carry or at 1,1 bit
       // & is used for carry and left shit to move it at respective position.
       
      return b == 0 ? a : getSum(a ^ b, (unsigned int)(a & b) << 1);
    }
};