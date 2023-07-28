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
 * A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in
 * the sequence has an edge connecting them. A node can only appear in the sequence at
 * most once. Note that the path does not need to pass through the root.
 *
 * The path sum of a path is the sum of the node's values in the path.
 *
 * Given the root of a binary tree, return the maximum path sum of any non-empty path.
 *
 */
class Solution
{
public:
    int pathSum(TreeNode *root, int &res)
    {
        if (!root)
        {
            return 0;
        }
        int l = pathSum(root->left, res);
        int r = pathSum(root->right, res);

        int x = max(max(l, r) + root->val, root->val);
        int y = max(x, l + r + root->val);
        res = max(res, y);
        return x;
    }
    int maxPathSum(TreeNode *root)
    {
        int res = INT_MIN;
        pathSum(root, res);
        return res;
    }
};