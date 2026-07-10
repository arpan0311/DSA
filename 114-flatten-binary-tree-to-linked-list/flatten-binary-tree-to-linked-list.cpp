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
// root left  right
// preorder  
    void preorder(TreeNode* root,vector<TreeNode*>&answer){
        if(!root){
            return;
        }
        answer.push_back(root);
        preorder(root->left,answer);
        preorder(root->right,answer);
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*>answer;
        preorder(root,answer);
        int i=0;
        while(i<answer.size()){
             root =answer[i];
            root->left=nullptr;
            if(i+1<answer.size()){
            root->right=answer[i+1];
            }
            else{
                root->right=nullptr;
            }
            root=root->right;
            i++;
        }
    }
};