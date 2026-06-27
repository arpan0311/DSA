class Solution {
public:
    int find_ind(vector<int>& nums, int s, int e, int target) {
        for (int i = s; i <= e; i++) {
            if (nums[i] == target)
                return i;
        }
        return -1;
    }

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,
                    int s, int e, int &curr) {

        if (s > e) return nullptr;

        TreeNode* root = new TreeNode(preorder[curr]);

        int index = find_ind(inorder, s, e, preorder[curr]);

        curr++;

        root->left = solve(preorder, inorder, s, index - 1, curr);
        root->right = solve(preorder, inorder, index + 1, e, curr);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int curr = 0;
        return solve(preorder, inorder, 0, inorder.size() - 1, curr);
    }
};