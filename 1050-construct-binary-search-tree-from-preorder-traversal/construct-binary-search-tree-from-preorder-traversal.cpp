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
    TreeNode* arpan(vector<int>&A,int &i,int maxi){
        if(i==A.size()||A[i]>maxi){
            return NULL;
        }
        TreeNode* root =new TreeNode(A[i++]);
        root->left=arpan(A,i,root->val);
        root->right=arpan(A,i,maxi);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& A) {
        int i=0,maxi=INT_MAX;
        // Tree* root=
        return arpan(A,i,maxi);
    }
};