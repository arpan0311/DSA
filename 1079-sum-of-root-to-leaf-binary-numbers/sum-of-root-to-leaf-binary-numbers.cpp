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
    void solve(TreeNode* root, string s, vector<string>& answer) {
        if(!root){
            return;
        }
         s.push_back(root->val+'0');
        if (root->left == nullptr && root->right == nullptr) {
            answer.push_back(s);
            return;
        }

        if (root->left) {
            solve(root->left, s, answer);
        }

         if (root->right) {
            solve(root->right, s, answer);
        }
    }
    int binaryToDecimal(string s) {
        int n = s.length();
        int power = 1; // 2^0
        int ans = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') {
                ans += power;
            }
            power *= 2;
        }

        return ans;
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<string> answer;
        string s = "";
        solve(root, s, answer);
        long long sum = 0;
        for (int i = 0; i < answer.size(); i++) {
            sum += binaryToDecimal(answer[i]);
        }
        return sum;
    }
};