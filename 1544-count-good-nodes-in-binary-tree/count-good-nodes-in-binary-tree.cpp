/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root, int maxi) {
        if (!root) {
            return 0;
        }
        maxi=max(maxi,root->val);
        if(root->val>=maxi){
            return 1+ solve(root->left,maxi)+solve(root->right,maxi);
        }
        return solve(root->left,maxi)+solve(root->right,maxi);
    }
    int goodNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int maxi=INT_MIN;
        return solve(root,maxi)==0?1:solve(root,maxi);
    }
};