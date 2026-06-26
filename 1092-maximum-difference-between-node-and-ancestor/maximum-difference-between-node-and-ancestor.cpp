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
void dfs(TreeNode* root,int& diff,int maxi,int mini){
    if(!root){
        return ;
    }
    maxi=max(maxi,root->val);
    mini=min(mini,root->val);
    diff=max(diff,abs(maxi-mini));
    if(root->left){
        dfs(root->left,diff,maxi,mini);
    }
    if(root->right){
        dfs(root->right,diff,maxi,mini);
    }

}
    int maxAncestorDiff(TreeNode* root) {
        if(!root){
            return 0;
        }
        int diff=0;
        int maxi=root->val;
        int mini=root->val;
        dfs(root,diff,maxi,mini);
        return diff;
    }
};