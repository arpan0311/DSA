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
    void inorder(TreeNode* root,vector<int>&answer){
        if(!root){
            return;
        }

        if(root->left){
            inorder(root->left,answer);
        }
        answer.push_back(root->val);
        if(root->right){
            inorder(root->right,answer);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        // inorder left root right
        vector<int>answer;
        inorder(root,answer);
        return answer;
    }
};