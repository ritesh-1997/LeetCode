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
 * Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
 * Return the smallest level x such that the sum of all the values of nodes at level x is maximal.
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
    void levelOrder(TreeNode *root, int level, vector<int> &v)
    {
        if (!root)
        {
            return;
        }
        if (level == 1)
        {
            v.push_back(root->val);
        }
        levelOrder(root->left, level - 1, v);
        levelOrder(root->right, level - 1, v);
    }
    int maxLevelSum(TreeNode *root)
    {
        int h = height(root);
        int res = INT_MIN, level = 1;
        for (int i = 1; i <= h; i++)
        {
            vector<int> v;
            int sum = 0;
            levelOrder(root, i, v);
            for (auto j : v)
            {
                sum += j;
            }
            if (sum > res)
            {
                res = sum;
                level = i;
            }
        }
        return level;
    }
};