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
    void find_diff(TreeNode* root, TreeNode* child, int& maxidiff) {
        if (!child) {
            return;
        }
        maxidiff = max(maxidiff, abs(root->val - child->val));
        find_diff(root, child->left, maxidiff);
        find_diff(root, child->right, maxidiff);
    }
    void bfs(TreeNode* root, int& maxidiff) {
        // base case
        if (!root) {
            return;
        }

        // root left right

        if (root->left) {
             find_diff(root, root->left, maxidiff);
        }
        if (root->right) {
             find_diff(root, root->right, maxidiff);
        }
        bfs(root->left, maxidiff);
        bfs(root->right, maxidiff);
    }
    int maxAncestorDiff(TreeNode* root) {
        int maxidiff = 0;
        bfs(root, maxidiff);
        return maxidiff;
    }
};