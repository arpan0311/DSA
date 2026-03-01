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
void path(TreeNode* root,TreeNode* p,vector<TreeNode*>&ans){
    if(!root){
        return ;
    }
    if(root->val==p->val){
        ans.push_back(root);
        return;
    }
    if(root->val<p->val){
        ans.push_back(root);
        path(root->right,p,ans);
    }
    else{
        ans.push_back(root);
        path(root->left,p,ans);
    }
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>pathA;
        path(root,p,pathA);
        vector<TreeNode*>pathB;
        path(root,q,pathB);
        set<TreeNode*>st;
        for(int i=pathA.size()-1;i>=0;i--){
            st.insert(pathA[i]);
        }
        for(int i=pathB.size()-1;i>=0;i--){
            if(st.find(pathB[i])!=st.end()){
                return pathB[i];
            }
        }
        return root;
    }
};