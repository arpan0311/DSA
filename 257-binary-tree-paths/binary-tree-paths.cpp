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
    void bfs(TreeNode* root, string s, vector<string>& answer) {
        if (root == NULL) {
            return;
        }

        s += to_string(root->val);

        // Leaf node
        if (root->left == NULL && root->right == NULL) {
            answer.push_back(s);
            return;
        }

        s += "->";

        if (root->left) {
            bfs(root->left, s, answer);
        }

        if (root->right) {
            bfs(root->right, s, answer);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> answer;
        string s = "";
        bfs(root, s, answer);
        return answer;
    }
};