class Solution {
public:
    int count1s(int n){
        int res = 0;
        while(n){
            res += (n&1);
            n >>=1;
        }
        return res;
    }
    vector<int> countBits(int n) {
        vector<int> res(n+1,0);

        for(auto i = 0;i<=n;i++){
            int count = count1s(i);
            res[i] = count;
        }

        return res;
    }
};