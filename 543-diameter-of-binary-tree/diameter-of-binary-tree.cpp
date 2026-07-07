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
    int max_diameter=0;
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
    void Dfs(TreeNode* root){
        if(!root){
            return ;
        }
        Dfs(root->left);
        Dfs(root->right);
        int d1=maxDepth(root->left);
        int d2=maxDepth(root->right);
        max_diameter=max(max_diameter,d1+d2);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        Dfs(root);
        return max_diameter;
    }
};