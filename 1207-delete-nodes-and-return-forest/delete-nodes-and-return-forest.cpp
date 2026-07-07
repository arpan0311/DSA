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
    TreeNode* dfs(TreeNode* root,unordered_set<int>st,vector<TreeNode*>&res){
        if(!root){
            return NULL;
        }
        root->left=dfs(root->left,st,res);
        root->right=dfs(root->right,st,res);
        if(st.find(root->val)!=st.end()){
            if(root->left){
                res.push_back(root->left);
            }

            if(root->right){
                res.push_back(root->right);
            }
            return NULL;
        }

        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& nums) {
        if(!root){
            return {};
        }
        unordered_set<int>st;
        vector<TreeNode*>result;

        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }

         root =dfs(root,st,result);

        if(root&&st.find(root->val)==st.end()){
            result.push_back(root);
        }
        return result;
    }   
};