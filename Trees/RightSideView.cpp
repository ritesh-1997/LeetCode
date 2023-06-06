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
 * Given the root of a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
 */
class Solution
{
public:
    int height(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        return max(height(root->left) + 1, height(root->right) + 1);
    }

    vector<int> levelOrder(TreeNode *root, int h, vector<int> &v)
    {
        if (!root)
        {
            return v;
        }
        if (v.size() == h)
        {
            v.push_back(root->val);
        }
        v = levelOrder(root->right, h + 1, v);
        v = levelOrder(root->left, h + 1, v);
        return v;
    }
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        res = levelOrder(root, 0, res);
        return res;
    }
};