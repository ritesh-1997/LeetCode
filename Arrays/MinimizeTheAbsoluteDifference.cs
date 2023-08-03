/*
Given three sorted arrays A, B  and Cof not necessarily same sizes.

Calculate the minimum absolute difference between the maximum and minimum 
number from the triplet a, b, c such that a, b, c belongs arrays A, B, C respectively.

i.e. minimize | max(a,b,c) - min(a,b,c) |.

Example :

Input:

A : [ 1, 4, 5, 8, 10 ]
B : [ 6, 9, 15 ]
C : [ 2, 3, 6, 6 ]
Output:
1
Explanation: We get the minimum difference for a=5, b=6, c=6 as | max(a,b,c) - min(a,b,c) | = |6-5| = 1.s
*/
using System;
class Solution {
    public int solve(List<int> A, List<int> B, List<int> C) {
        int i = 0;
        int j = 0;
        int k = 0;
        
        int min_diff,curr,min_term;
        min_diff = Math.Max(A[i],Math.Max(B[j],C[k]))-Math.Min(A[i],Math.Min(B[j],C[k]));
        
        while(i<A.Count&&j<B.Count&&k<C.Count){
            int min_ = Math.Min(A[i],Math.Min(B[j],C[k]));
            int max_ = Math.Max(A[i],Math.Max(B[j],C[k]));
            curr = max_-min_;
            min_diff = Math.Min(min_diff,curr);
            
            // we have minimize the diff            
            if(A[i]==min_)
                i+=1;
            else if(B[j]==min_)
                j+=1;
            else
                k+=1;
        }
        return min_diff;
    }
}
