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
    void path(TreeNode* root,string s,vector<string>&ans){
        if(!root->left&&!root->right){
            s.push_back(root->val+'a');
           reverse(s.begin(),s.end());
            ans.push_back(s);
            return;
        }
        if(root->left){

            s.push_back(root->val+'a');
            path(root->left,s,ans);
           s.pop_back();
        }
        if(root->right){
            s.push_back(root->val+'a');
            path(root->right,s,ans);
            s.pop_back();
        }
    }
    string smallestFromLeaf(TreeNode* root) {
        vector<string>answer;
        string s="";
        path(root,s,answer);
        sort(answer.begin(),answer.end());
        for(int i=0;i<answer.size();i++){
            cout<<answer[i]<<" ";
        }
        return answer[0];
    }
};