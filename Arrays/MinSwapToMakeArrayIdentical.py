from os import *
from sys import *
from collections import *
from math import *

from typing import List

def minSwapToSort(B,n):
    arrPos = [[0 for x in range(2)]
                 for y in range(n)]
    for i in range(n):
        arrPos[i][0] = B[i]
        arrPos[i][1] = i
    arrPos.sort()
    vis = [False]*n
    ans = 0
    for i in range(n):
        if(vis[i] or arrPos[i][1] ==i):
            continue
        cycle_zero =0
        j=i
        while(not vis[j]):
            vis[j] = 1
            j = arrPos[j][1]
            cycle_zero +=1
        ans +=(cycle_zero-1)
    return ans
def minimumSwaps(A: List[int], B: List[int]):
    # Write your code here.
    mp = {}
    # storing index of element of B in map
    for i in range(len(B)):
        mp[B[i]] = i
    # Storing location of A element in B element position
    for i in range(len(B)):
        B[i] = mp[A[i]]
    return minSwapToSort(B,len(B))
    pass
