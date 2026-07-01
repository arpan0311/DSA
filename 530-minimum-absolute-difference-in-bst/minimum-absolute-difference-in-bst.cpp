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
    int getMinimumDifference(TreeNode* root) {
        // inorder left root right
        vector<int>answer;
        inorder(root,answer);
        sort(answer.begin(),answer.end());
        int mini=INT_MAX;
        for(int i=0;i<answer.size()-1;i++){
            mini=min(mini,answer[i+1]-answer[i]);
        }
        return mini;
    }
};