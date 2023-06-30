from os import *
from sys import *
from collections import *
from math import *

'''

    Following is the class TreeNode structure

    class   TreeNode :
        def __init__(self, val) :
            self.val = val
            self.left = None
            self.right = None

'''
def sum(root):
    if(root):
        return (root.val+sum(root.left)+sum(root.right))
    else:
        return 0;
def isSumTree(root):
    # Write your code here.
    if(root is None or (root.left is None and root.right is None)):
        return True;
    ls = sum(root.left)
    rs = sum(root.right)

    if(root.val == (ls+rs) and isSumTree(root.left) and isSumTree(root.right)):
        return True
    return False
    pass
    