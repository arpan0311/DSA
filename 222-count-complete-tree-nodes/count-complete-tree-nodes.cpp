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
int left_height(TreeNode* left){
    TreeNode* temp=left;
    int lh=0;
    while(temp!=nullptr){
        lh++;
        temp=temp->left;
    }
    return lh;
}
int right_height(TreeNode* right){
    TreeNode* temp=right;
    int rh=0;
    while(temp!=nullptr){
        rh++;
        temp=temp->right;
    }
    return rh;
}
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        int lh=left_height(root);
        int rh=right_height(root);

        if(lh==rh){
            return pow(2,lh)-1;
        }
        return 1+ countNodes(root->left) + countNodes(root->right);
    }
};