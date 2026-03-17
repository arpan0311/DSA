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
    void solve(TreeNode* root,int target,vector<int>value,vector<vector<int>>&answer,int currSum){
        if(!root->left&&!root->right){
            if(currSum==target){
                answer.push_back(value);
            }
            return;
        }
        if(root->left){
            value.push_back(root->left->val);
            solve(root->left,target,value,answer,currSum+root->left->val);
            value.pop_back();
        }
        if(root->right){
            value.push_back(root->right->val);
            solve(root->right,target,value,answer,currSum+root->right->val);
        }

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root){
            return {};
        }
        vector<vector<int>>answer;
        vector<int>value;
        int currSum=root->val;
        value.push_back(root->val);
        solve(root,targetSum,value,answer,currSum);
        return answer;
    }
};