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
    void dfs(TreeNode* root) {
        if (!root) {
            return;
        }
        // post order 
        dfs(root->left);
        dfs(root->right);
        TreeNode* root_left = root->left;
        root->left = root->right;
        root->right = root_left;
        
    }
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return root;
        }
        dfs(root);
        return root;
    }
};