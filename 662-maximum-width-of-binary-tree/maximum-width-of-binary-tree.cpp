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
    int widthOfBinaryTree(TreeNode* root) {
        // jahan bhi null h wahan pe -1 dal do and maximum size of temp array
        // will be our answer
        if (!root) {
            return 0;
        }
        long long maxi = 0;
        queue<pair<TreeNode*, long long>>q;
        q.push({root, 0});
        while (!q.empty()) {
            int size = q.size();
            long long mini = q.front().second;
            long long last, first;
            for (int i = 0; i < size; i++) {
                TreeNode* curr=q.front().first;
                long long curr_ind = q.front().second - mini;
                q.pop();
                if (i == 0) {
                    first = curr_ind;
                }
                if (i == size - 1) {
                    last = curr_ind;
                }

                if (curr->left) {
                    q.push({curr->left, 2 * curr_ind + 1});
                }
                if (curr->right) {
                    q.push({curr->right, 2 * curr_ind + 2});
                }
            }
            maxi = max(maxi, last - first + 1);
        }
        return maxi;
    }
};