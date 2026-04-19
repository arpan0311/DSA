/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool bfs(TreeNode* root) {
        if (!root) {
            return true;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool seenNull = false;
        while (!q.empty()) {
            int node = q.size();

            for (int i = 0; i < node; i++) {
                TreeNode* curr = q.front();
                // right exist but left doesn't exist
                if (curr->right && !curr->left) {
                    return false;
                }
                // curr exist but previous doesn't
                if (seenNull && (curr->left || curr->right)) {
                    return false;
                }
                // both exist

                if (curr->left) {
                    q.push(curr->left);
                } else {
                    seenNull = true;
                }
                if (curr->right) {
                    q.push(curr->right);
                }
                else{
                    seenNull = true;
                }
               
                q.pop();
            }
        }
        return true;
    }
    bool isCompleteTree(TreeNode* root) { return bfs(root); }
};