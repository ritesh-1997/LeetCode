# Given a rows x cols binary matrix filled with 0's and 1's, 
# find the largest rectangle containing only 1's and return its area.
class Solution:

    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        n = len(matrix)
        m = len(matrix[0])
        v = [0]*m
        res = 0
        for i in range(0,n):
            for j in range(0,m):
                if matrix[i][j]=='1':
                    v[j] = v[j]+1
                else:
                    v[j] = 0
            st =[]
            left = []
            
            for x in range(m):
                while st and v[st[-1]]>=v[x]:
                    st.pop()
                if len(st)==0:
                    left.append(-1)    
                else:
                    left.append(st[-1])
                st.append(x)

            st = []
            right = []
            for x in range(m-1,-1,-1):
                while st and v[st[-1]]>=v[x]:
                    st.pop()
                if len(st)==0:
                    right.append(m)    
                else:
                    right.append(st[-1]) 
                st.append(x)
            right.reverse()
            
            mah = 0
            print(v,right,left)
            for x in range(m):
                w = right[x]-left[x]-1
                area = w*v[x]
                # print(area)
                mah = max(area,mah)
            res = max(res,mah)
        return res