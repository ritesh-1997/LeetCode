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
 * You are given the root of a binary tree containing digits from 0 to 9 only.
 *
 * Each root-to-leaf path in the tree represents a number.
 *
 * For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
 *
 * Return the total sum of all root-to-leaf numbers. Test cases are generated
 * so that the answer will fit in a 32-bit integer.
 *
 * A leaf node is a node with no children.


*/
class Solution
{
public:
    void util(TreeNode *root, int &res, int sum)
    {
        if (!root)
        {
            return;
        }
        sum = sum * 10 + root->val;
        if (!root->left && !root->right)
        {
            res += sum;
            return;
        }
        util(root->left, res, sum);
        util(root->right, res, sum);
    }
    int sumNumbers(TreeNode *root)
    {
        int res = 0;
        util(root, res, 0);
        return res;
    }
};