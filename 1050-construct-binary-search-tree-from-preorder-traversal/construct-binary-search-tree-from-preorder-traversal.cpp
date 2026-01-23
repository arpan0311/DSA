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
    
    TreeNode* makeTree(vector<int>&preorder,vector<int>&inorder,unordered_map<int,int>&hash,int i,int n,int &curr){
        int size=preorder.size();
        if(i>n){
            return NULL;
        }

        if(curr>=size){
            return NULL;
        }
        int value=preorder[curr++];
       TreeNode* root= new TreeNode(value);
        int mid=hash[value];
        root->left=makeTree(preorder,inorder,hash,i,mid-1,curr);
        root->right=makeTree(preorder,inorder,hash,mid+1,n,curr);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        unordered_map<int,int>hash;
       
        vector<int>inorder(preorder.begin(),preorder.end());
        sort(inorder.begin(),inorder.end());
         for(int i=0;i<inorder.size();i++){
            hash[inorder[i]]=i;
        }
        // now I have inorder and preorder so 
        int i=0,n=preorder.size()-1;
        int curr=0;
       return makeTree(preorder,inorder,hash,i,n,curr);
    }
};