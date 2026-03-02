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
    int maxi = 0;
    map<TreeNode*, int> hash;
    void depth(TreeNode* root,int cnt) {
        if (!root) {
            return;
        }
        maxi = max(maxi, cnt);
        hash[root] = cnt;
        if (root->left) {
            depth(root->left, cnt + 1);
        }
        if (root->right) {
            depth(root->right, cnt + 1);
        }
    }
    TreeNode* lcs(TreeNode* root, int cnt) {

        if (!root) {
            return nullptr;
        }
        if (maxi == cnt) {
            return root;
        }

        TreeNode* left1 = lcs(root->left, cnt + 1);

        TreeNode* right1 = lcs(root->right, cnt + 1);

        if (left1 && right1) {
            return root;
        }
        if(!left1){
            return right1;
        }
        return left1;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int cnt = 0;
        depth(root, cnt);
        return lcs(root, cnt);
    }
};