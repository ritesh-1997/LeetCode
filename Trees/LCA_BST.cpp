/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void searchBST(TreeNode *root, TreeNode *p,vector<TreeNode *> & v){
        if(!root){
            return;
        }
        if(root->val == p->val){
            v.push_back(root);
            return;
        }
        if(p->val>root->val){
            v.push_back(root);
            searchBST(root->right,p,v);
        }
        else{
            v.push_back(root);
            searchBST(root->left,p,v);            
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> v,w;

        //finding path
        searchBST(root,p,v);
        searchBST(root,q,w);
        
        int n = v.size(),m = w.size();

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(v[i]==w[j]){
                    return v[i];
                }
            }
        }

        return root;
    }
};


/**
 * 
 * New Solution
*/



class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      
      if(root== NULL) return root; 

      if(p->val > root->val and q->val > root->val)
      return lowestCommonAncestor(root->right ,p ,q) ;

      else if(p->val <root->val and q->val< root->val) 
      return lowestCommonAncestor(root->left , p ,q);

      return root;

    }
};