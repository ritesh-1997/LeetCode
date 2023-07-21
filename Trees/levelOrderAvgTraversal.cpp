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
 * Given the root of a binary tree, return the average value of
 * the nodes on each level in the form of an array. Answers within
 * 10-5 of the actual answer will be accepted.
 */
class Solution
{
public:
    int height(TreeNode *root)
    {
        if (!root)
            return 0;
        return max(height(root->left) + 1, height(root->right) + 1);
    }
    void levelOrder(TreeNode *root, int height, vector<int> &v)
    {
        if (!root)
        {
            return;
        }
        if (height == 0)
        {
            v.push_back(root->val);
            return;
        }
        levelOrder(root->left, height - 1, v);
        levelOrder(root->right, height - 1, v);
    }
    vector<double> averageOfLevels(TreeNode *root)
    {
        int h = height(root);
        vector<double> res;
        for (int i = 0; i < h; i++)
        {
            vector<int> v;
            levelOrder(root, i, v);
            double sum = 0;
            for (auto num : v)
            {
                sum += num;
            }
            res.push_back(sum / v.size());
        }
        return res;
    }
};