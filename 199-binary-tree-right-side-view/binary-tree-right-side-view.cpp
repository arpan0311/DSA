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
void bfs(TreeNode* root,vector<int>&answer){
    if(!root){
        return;
    }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int node=q.size();
            vector<int>curr;
            for(int i=0;i<node;i++){
                TreeNode* temp=q.front();
                curr.push_back(temp->val);
                 if(temp->left!=nullptr){
                    q.push(temp->left);
                }
                if(temp->right!=nullptr){
                    q.push(temp->right);
                }
               
                q.pop();
            }
            answer.push_back(curr.back());
        }
        
}
    vector<int> rightSideView(TreeNode* root) {
        vector<int>answer;
        bfs(root,answer);
        return answer;
    }
};