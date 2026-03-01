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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        if (root == NULL || root == p || root == q) {
            return root;
        }
        TreeNode* rootleft = lowestCommonAncestor(root->left, p, q);
        TreeNode* rootright = lowestCommonAncestor(root->right, p, q);
        if (rootleft == nullptr) {
            return rootright;
        } else if (rootright == nullptr) {
            return rootleft;
        } else {
            return root;
        }
    }
};