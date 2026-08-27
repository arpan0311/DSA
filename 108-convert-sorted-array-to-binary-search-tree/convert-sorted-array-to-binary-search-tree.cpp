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
  TreeNode* build_tree(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int mid = (left + right) / 2;
        TreeNode* head = new TreeNode(nums[mid]);
        head->left = build_tree(nums, left, mid - 1);
        head->right = build_tree(nums, mid + 1, right);
        return head;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       return build_tree(nums,0,nums.size()-1);
    }
};