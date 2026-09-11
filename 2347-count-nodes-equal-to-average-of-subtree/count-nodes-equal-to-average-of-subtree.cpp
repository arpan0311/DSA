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
int res=0;
// here I'm calculating the sum
    int sum(TreeNode* root,int &cnt){
        if(!root){
            return 0;
        }
        cnt++;
        return root->val+sum(root->left,cnt)+sum(root->right,cnt);
    }
    // check each root 
    int answer(TreeNode* root){
        if(!root){
            return 0;
        }
        int l1=0,l2=0;
        int left=sum(root->left,l1);
        int right=sum(root->right,l2);
        cout<<left<<" "<<right<<" ";
        cout<<endl;
        if(root->val==(left+right+root->val)/(l1+l2+1)){
            res++;
        }

        answer(root->left);
        answer(root->right);
        return -1;
    }
    int averageOfSubtree(TreeNode* root) {
        answer(root);
        return res;
    }
};