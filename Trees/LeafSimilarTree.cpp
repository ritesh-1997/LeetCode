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
 * Consider all the leaves of a binary tree, from left to right order, the values of those
 * leaves form a leaf value sequence.
 *
 * For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).
 *
 * Two binary trees are considered leaf-similar if their leaf value sequence is the same.
 *
 * Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.
 */

class Solution
{
public:
    void leaf(TreeNode *root, vector<int> &v)
    {
        if (!root)
        {
            return;
        }
        else if (root->left == NULL && root->right == NULL)
        {
            v.push_back(root->val);
            return;
        }
        leaf(root->left, v);
        leaf(root->right, v);
    }
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> v1, v2;
        leaf(root1, v1);
        leaf(root2, v2);

        return (v1 == v2) ? true : false;
    }
};