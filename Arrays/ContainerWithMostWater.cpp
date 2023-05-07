class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        vector<int> LMax(n,0),RMax(n,0);   

        LMax[0] = height[0];
        for(int i=1;i<n;i++){
            LMax[i] = max(LMax[i-1],height[i]);
        }

        RMax[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
            RMax[i] = max(RMax[i+1],height[i]);
        }

        int l = 0,r=n-1, area = 0,res = 0;

        // goto from left and right and find area
        while(l<=r){
            area = min(LMax[l],RMax[r])*(r-l);
            res = max(res,area);

            // To maximize the area if left height is less than right height
            // then increment left to find bigger height otherwise decrement right.
            if(height[l]<height[r])
                l++;
            else
                r--;
        }
        return res;
    }
};