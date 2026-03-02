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
    void bfs(TreeNode* root,int maxi,int mini,int &max_diff){
        if(!root){
            return;
        }
        maxi=max(maxi,root->val);
        mini=min(mini,root->val);
        max_diff=max(max_diff,abs(maxi-mini));
        bfs(root->left,maxi,mini,max_diff);
        bfs(root->right,maxi,mini,max_diff);
    }
    int maxAncestorDiff(TreeNode* root) {
        int maxi=root->val,mini=root->val;
        int max_diff=abs(maxi-mini);
        bfs(root,maxi,mini,max_diff);
        return max_diff;
    }
};