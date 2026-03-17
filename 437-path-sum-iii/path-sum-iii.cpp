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
    void solve(TreeNode* root, int targetSum, unordered_map<long long, int>& hash,
               int& cnt, long long sum) {
       
        if (!root) {
            return;
        }
          if (root) {
            sum += root->val;
        }
        if (hash.find(sum - targetSum) != hash.end()) {
            cnt += hash[sum - targetSum];
        }
       
        
        hash[sum]++;

        if (root->left) {
            solve(root->left,targetSum,hash,cnt,sum);
        }
        if(root->right){
             solve(root->right,targetSum,hash,cnt,sum);
        }
        hash[sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        // dfs with unordered_map
        if(!root){
            return 0;
        }
        unordered_map<long long, int> hash;
        hash[0] = 1;
        int cnt = 0;
        long long sum = 0;
        solve(root, targetSum, hash, cnt, sum);
        return cnt;
    }
};