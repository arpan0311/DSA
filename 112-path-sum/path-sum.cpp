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
    bool solve(TreeNode* root, int target, int sum) {
        // base condition
        if (!root) {
            return sum == target;
        }
        if (!root->left && !root->right) {
            return sum == target;
        }
        
       return (root->left && solve(root->left, target, sum + root->left->val)) ||
       (root->right && solve(root->right, target, sum + root->right->val));
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root){
            return false;
        }
        int value = root->val;
        return solve(root, targetSum, value);
    }
};