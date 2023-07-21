/**
 * https://leetcode.com/problems/cousins-in-binary-tree/description/
 *
 * Given the root of a binary tree with unique values and the values of two different nodes
 * of the tree x and y, return true if the nodes corresponding to the values x and y in the
 * tree are cousins, or false otherwise.
 *
 * Two nodes of a binary tree are cousins if they have the same depth with different parents.
 *
 *
 * Note that in a binary tree, the root node is at the depth 0, and children of
 *  each depth k node are at the depth k + 1.
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
    int xlvl = 0, ylvl = 0;
    TreeNode *xparent = NULL, *yparent = NULL;
    void dfs(TreeNode *root, int x, int y, int lvl = 0, TreeNode *parent = NULL)
    {
        if (!root)
        {
            return;
        }
        if (root->val == x)
        {
            xlvl = lvl;
            xparent = parent;
        }
        if (root->val == y)
        {
            ylvl = lvl;
            yparent = parent;
        }
        dfs(root->left, x, y, lvl + 1, parent = root);
        dfs(root->right, x, y, lvl + 1, parent = root);
    }

    bool isCousins(TreeNode *root, int x, int y)
    {
        // height should be same but parents not
        dfs(root, x, y);
        return xlvl == ylvl && xparent != yparent;
    }
};