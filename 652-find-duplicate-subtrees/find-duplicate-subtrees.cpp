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
    string dfs(TreeNode* root,vector<TreeNode*>&answer,unordered_map<string,int>&hash){
        if(!root){
             return "N";
        }
        string s=to_string(root->val)+","+dfs(root->left,answer,hash)+","+dfs(root->right,answer,hash);
        // only second time 
        if(hash[s]==1){
            answer.push_back(root);
        }
        hash[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int>hash;
        vector<TreeNode*>answer;
        dfs(root,answer,hash);
        return answer;
    }
};