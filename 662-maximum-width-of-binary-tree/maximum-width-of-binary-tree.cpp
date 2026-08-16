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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }

        queue<pair<TreeNode*,int>>q;
       
        long long answer=0;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            int mini=q.front().second;
             long long first,last;
            for(int i=0;i<size;i++){
long long val=q.front().second-mini;
                if(i==0){
                    first=val;
                }
                else if(i==size-1){
                    last=val;
                }
                TreeNode* curr=q.front().first;
                
                q.pop();
                if(curr->left){
                    q.push({curr->left,2*val+1});
                }
                if(curr->right){
                    q.push({curr->right,2*val+2});
                }
               
                
            }
            answer=max(answer,last-first+1);
        }
        return answer;
    }
};