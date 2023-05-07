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
    bool checkBST(TreeNode * root, long low, long high){
        if(!root){
            return true;
        }
        if(root->val>low && root->val<high){
            /**
             * To move left range will be from low to current root val
             * To move right range will be from current root val to high.
            */
            return checkBST(root->left,low,root->val) && checkBST(root->right,root->val,high);
        }
        else{
            return false;
        }
    }
    bool isValidBST(TreeNode* root) {
        if(!root){
            return true;
        }
        return checkBST(root,LONG_MIN,LONG_MAX);
    }
};