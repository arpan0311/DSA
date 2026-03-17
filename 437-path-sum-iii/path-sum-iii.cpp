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
    void solve(TreeNode* root,long long targetSum,long long value,int &cnt){
        if(value==targetSum){
            cnt++;
        }
        if(!root->left&&!root->right){
            return;
        }
        if(root->left){
            solve(root->left,targetSum,value+root->left->val,cnt);

        }
        if(root->right){
            solve(root->right,targetSum,value+root->right->val,cnt);
        }
        
    }
    void bfs(TreeNode* root,int targetSum,int &cnt){
        if(!root){
            return ;
        }
        int value=root->val;
        solve(root,targetSum,value,cnt);
        if(root->left){
            bfs(root->left,targetSum,cnt);
        }
        if(root->right){
            bfs(root->right,targetSum,cnt);
        }
    }
    int pathSum(TreeNode* root, int targetSum) {
        int cnt=0;
        bfs(root,targetSum,cnt);
        return cnt;
    }
};