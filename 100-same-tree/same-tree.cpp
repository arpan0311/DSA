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
bool arpan(TreeNode* p, TreeNode* q){
    if(!p&&q||p&&!q){
        return false;
    }
    if(p==nullptr&&q==nullptr){
        return true;
    }
    if(p->val!=q->val){
        return false;
    }
    return arpan(p->left,q->left)&&arpan(p->right,q->right);
}
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&!q){
            return true;
        }
        return arpan(p,q);
    }
};