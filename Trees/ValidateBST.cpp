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
 * Given the root of a binary tree, determine if it is a valid binary search tree (BST).
 *
 *
 * A valid BST is defined as follows:
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 */

class Solution
{
public:
    bool checkBST(TreeNode *root, long low, long high)
    {
        if (!root)
        {
            return true;
        }
        if (root->val > low && root->val < high)
        {
            return checkBST(root->left, low, root->val) && checkBST(root->right, root->val, high);
        }
        else
        {
            return false;
        }
    }
    bool isValidBST(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }
        return checkBST(root, LONG_MIN, LONG_MAX);
    }
};