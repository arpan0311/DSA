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
    void solve(TreeNode* root,string path,vector<string>&answer){
        if(!root->left&&!root->right){
            answer.push_back(path);
            return;
    }
    if(root->left){
        solve(root->left,path+"->"+to_string(root->left->val),answer);
    }
    if(root->right){
        solve(root->right,path+"->"+to_string(root->right->val),answer);
    }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string path=to_string(root->val);
        vector<string>answer;
        solve(root,path,answer);
        return answer;
    }
};