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
    int solve(TreeNode* root,string curr){
        // case of leaf node 
         if(!root){
            return 0;
        }
        if(!root->left&&!root->right){
            curr+=to_string(root->val);
            int num=stoi(curr);
            return num;
        }
       
        return solve(root->left, curr+to_string(root->val))+solve(root->right, curr+to_string(root->val));
    }
    int sumNumbers(TreeNode* root) {
        string s="";
        return solve(root,s);
    }
};