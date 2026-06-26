class Solution {
public:
    void dfs(TreeNode* root, unordered_map<long long, int>& hash,
             int& cnt, long long sum, int targetSum) {

        if (root == nullptr) {
            return;
        }

        sum += root->val;

        if (hash.find(sum - targetSum) != hash.end()) {
            cnt += hash[sum - targetSum];
        }

        hash[sum]++;

        dfs(root->left, hash, cnt, sum, targetSum);
        dfs(root->right, hash, cnt, sum, targetSum);

        hash[sum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> hash;
        hash[0] = 1;

        int cnt = 0;
        long long sum = 0;

        dfs(root, hash, cnt, sum, targetSum);

        return cnt;
    }
};