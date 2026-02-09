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
    void bfs(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }
        if (root->left) {
            bfs(root->left,ans);
        }
        if (root) {
            ans.push_back(root->val);
        }
        if (root->right) {
            bfs(root->right,ans);
        }
    }
    TreeNode* makeTree(vector<int>& ans, int s, int end) {
        if (s > end) {
            return NULL;
        }
        int mid = (s + end) / 2;
        TreeNode* root = new TreeNode(ans[mid]);
        root->left = makeTree(ans, s, mid-1);
        root->right = makeTree(ans, mid + 1, end);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        // firstly I need the sorted order of tree
        // use bfe to get sorted order
        vector<int> ans;
        bfs(root, ans);
        // form tree
        int len = ans.size();

        return makeTree(ans, 0, len-1);
    }
};