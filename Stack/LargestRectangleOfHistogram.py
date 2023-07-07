class Solution:
    def largestRectangleArea(self, height: List[int]) -> int:
        n = len(height)
        st =[]
        left = []
        for i in range(n):
            while st and height[st[-1]]>=height[i]:
                st.pop()
            if len(st)==0:
                left.append(-1)    
            else:
                left.append(st[-1])
            st.append(i)

        st = []
        right = []
        for i in range(n-1,-1,-1):
            while st and height[st[-1]]>=height[i]:
                st.pop()
            if len(st)==0:
                right.append(n)    
            else:
                right.append(st[-1]) 
            st.append(i)
        right.reverse()
        
        res = 0
        for i in range(n):
            w = right[i]-left[i]-1
            print(w,height[i])
            area = w*height[i]
            res = max(area,res)
        return res