from os import *
from sys import *
from collections import *
from math import *

# Following is the Binary Tree node structure:
class BinaryTreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def printLeftTree(root,ans):
    if(root):
        if(root.left):
            ans.append(root.data)
            printLeftTree(root.left,ans)
        elif(root.right):
            ans.append(root.data)
            printLeftTree(root.right,ans)

def printLeaf(root,ans):
    if(root):
        printLeaf(root.left,ans)
        if root.left is None and root.right is None:
            ans.append(root.data)
        printLeaf(root.right,ans)
def printRightTree(root,ans):
    if(root):
        if(root.right):
            printRightTree(root.right,ans)
            ans.append(root.data)
        elif(root.left):
            printRightTree(root.left,ans)
            ans.append(root.data)

def traverseBoundary(root):
    # Write your code here.
    ans=[]
    if(root is None):
        return ans
    if(root):
        ans.append(root.data)
        printLeftTree(root.left,ans)
        printLeaf(root.left,ans)
        printLeaf(root.right,ans)
        printRightTree(root.right,ans)
        return ans;
