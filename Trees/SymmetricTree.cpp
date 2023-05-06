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
class Solution {
public:
    bool inorder(TreeNode *root1, TreeNode *root2){
        
        // If both roots are null then return true
        if(!root1&&!root2){
            return true;
        }

        // If either of root is null then return false
        if(!root1 || !root2){
            return false;
        }

        // otherwise compare root value of both sub tree and 
        // call the recursice function by changing the left and right subtree
        return(root1->val==root2->val && inorder(root1->left,root2->right)&&(inorder(root1->right,root2->left)));
        
    }

    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return inorder(root->left,root->right);
    }
};