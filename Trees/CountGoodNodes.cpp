/**
 * Given a binary tree root, a node X in the tree is named good if
 * in the path from root to X there are no nodes with a value greater than X.
 *
 * Return the number of good nodes in the binary tree.
 */

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
class Solution
{
public:
    int c = 0;
    void sum(TreeNode *root, int max_)
    {
        if (!root)
        {
            return;
        }
        else if ((root->val) >= max_)
        {
            c++;
        }
        sum(root->left, max(max_, root->val));
        sum(root->right, max(max_, root->val));
    }
    int goodNodes(TreeNode *root)
    {
        sum(root, INT_MIN);
        return c;
    }
};