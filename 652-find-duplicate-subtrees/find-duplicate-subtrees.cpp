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
    string solve(TreeNode* root,unordered_map<string,int>&hash,vector<TreeNode*>&res){
        if(!root){
            return "N";
        }

        string s=to_string(root->val)+","+solve(root->left,hash,res)+","+solve(root->right,hash,res);
        if(hash[s]==1){
            res.push_back(root);
        }
        hash[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int>hash;

        vector<TreeNode*>answer;

        solve(root,hash,answer);

        return answer;

    }

};