/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 *
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined
 * between two nodes p and q as the lowest node in T that has both p and q as descendants
 * (where we allow a node to be a descendant of itself).”
 */

class Solution
{
public:
    bool FindNode(TreeNode *root, TreeNode *node, vector<TreeNode *> &v)
    {
        if (!root)
        {
            return false;
        }
        v.push_back(root);
        if (root == node)
        {
            return true;
        }
        if (FindNode(root->left, node, v) || FindNode(root->right, node, v))
        {
            return true;
        }
        v.pop_back();
        return false;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
        {
            return root;
        }
        TreeNode *ans;
        vector<TreeNode *> v1, v2;
        FindNode(root, p, v1);
        FindNode(root, q, v2);

        for (auto i = 0, j = 0; i < v1.size() && j < v2.size(); i++, j++)
        {
            if (v1[i] == v2[j])
            {
                ans = v1[i];
            }
            else
            {
                return ans;
            }
        }
        return ans;
    }
};