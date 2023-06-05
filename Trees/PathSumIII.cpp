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
 *
 * Given the root of a binary tree and an integer targetSum, return the
 * number of paths where the sum of the values along the path equals targetSum.
 *
 * The path does not need to start or end at the root or a leaf, but it must go
 * downwards (i.e., traveling only from parent nodes to child nodes).
 */

class Solution
{
public:
    int c = 0;
    void sum_(TreeNode *root, long long int target)
    {

        if (!root)
        {
            return;
        }
        if (root->val == target)
        {
            c++;
        }
        sum_(root->left, target - root->val);
        sum_(root->right, target - root->val);
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
        {
            return 0;
        }
        sum_(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return c;
    }
};