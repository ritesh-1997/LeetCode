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
    int height(TreeNode *root){
        if(!root){
            return 0;
        }
        return max(height(root->left)+1,height(root->right)+1);
    }
    void levelTraversal(TreeNode *r, int level,vector<int>& v){
        if(!r||level == 0){
            return;
        }
        if(level == 1){
            v.push_back(r->val);
        }
        
        levelTraversal(r->left,level-1,v);
        levelTraversal(r->right,level-1,v);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;

        int h = height(root);

        for(int i=1;i<=h;i++){
            vector<int> v;
            levelTraversal(root,i,v);
            res.push_back(v);
            v.clear();
        }
        return res;
    }
};