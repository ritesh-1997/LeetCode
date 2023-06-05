/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/**
 * You are given the root of a binary tree.
 *
 * A ZigZag path for a binary tree is defined as follow:
 *
 * Choose any node in the binary tree and a direction (right or left).
 *
 * If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
 *
 * Change the direction from right to left or from left to right.
 *
 * Repeat the second and third steps until you can't move in the tree.
 *
 * Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).
 *
 * Return the longest ZigZag path contained in that tree.
 */

class Solution
{
public:
    pair<int, int> dfs(TreeNode *root, int &len)
    {
        if (!root)
        {
            return {0, 0};
        }
        // right
        auto left = dfs(root->left, len);
        auto right = dfs(root->right, len);

        int leftMax = left.second, rightMax = right.first;
        len = max(len, max(rightMax, leftMax));
        return {1 + leftMax, rightMax + 1};
    }
    int longestZigZag(TreeNode *root)
    {
        int maxLen = 0;
        dfs(root, maxLen);
        return maxLen;
    }
};