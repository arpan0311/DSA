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
    // find the path of bruteforce 
    bool getPath(TreeNode* root,TreeNode* p,vector<TreeNode*>&path){
        if(!root){
            return false;
        }
        path.push_back(root);
        if(root==p){
            return true;
        }
        if(getPath(root->left,p,path)||getPath(root->right,p,path)){
            return true;
        }
       
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>a,b;
        TreeNode* temp=root;
        getPath(temp,p,a);
        getPath(root,q,b);
        TreeNode* prev=nullptr;

        for(int i=0;i<min(a.size(),b.size());i++){
            if(a[i]!=b[i]){
                return prev;
            }
            prev=a[i];
        }

        return prev;
    }
};