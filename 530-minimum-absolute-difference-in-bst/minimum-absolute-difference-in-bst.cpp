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
    TreeNode*  prev=nullptr;
    void inorder(TreeNode* root,int& diff){
        if(!root){
            return;
        }
        if(root->left){
            inorder(root->left,diff);
        }
        if(prev){
            diff=min(diff,root->val-prev->val);
        }
        prev=root;
        if(root->right){
           inorder(root->right,diff);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        // root left right  
        int diff=INT_MAX;
        inorder(root,diff);
        return diff;
    }
};