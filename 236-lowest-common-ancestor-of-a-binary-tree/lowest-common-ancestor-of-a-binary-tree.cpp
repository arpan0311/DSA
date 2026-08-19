TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q) {

    if (!root) {
        return nullptr;
    }

    TreeNode* left = solve(root->left, p, q);

    TreeNode* right = solve(root->right, p, q);
    // case one

    if (left && right) {
        return root;
    }

    if (root->val == p->val || root->val == q->val) {
        return root;
    }

    return (left == nullptr ? right : left);
}
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);
    }
};