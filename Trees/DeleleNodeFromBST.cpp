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
 * Given a root node reference of a BST and a key, delete the node with the given key in the BST.
 * Return the root node reference (possibly updated) of the BST.
 *
 * Basically, the deletion can be divided into two stages:
 *
 * Search for a node to remove.
 *
 * If the node is found, delete the node.
 */

class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root)
        {
            // calling to find the node
            if (key < root->val)
                root->left = deleteNode(root->left, key);
            else if (key > root->val)
            {
                root->right = deleteNode(root->right, key);
            }
            else
            {
                // if root->val == key

                // leaf node
                if (!root->left && !root->right)
                {
                    return NULL;
                }
                // only one child
                if (!root->left || !root->right)
                {
                    return root->left ? root->left : root->right;
                }
                // both present find LMC of RST or RMC of LST
                //  we are choosing RMC of LST

                // we can go for LMC of RST by changing node
                // left to right and right to left

                TreeNode *temp = root->left;

                // going till last right child
                while (temp->right != NULL)
                {
                    temp = temp->right;
                }
                // replacing root val to RMC of LST.
                root->val = temp->val;
                // then with leaf condition it will delete it.
                root->left = deleteNode(root->left, temp->val);
            }
        }
        return root;
    }
};