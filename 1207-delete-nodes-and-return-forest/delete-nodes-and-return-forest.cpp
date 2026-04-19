class Solution {
public:
    TreeNode* answer(TreeNode* root, unordered_set<int>& st,
                     vector<TreeNode*>& result) {
        if (!root) return NULL;
        root->left = answer(root->left, st, result);
        root->right = answer(root->right, st, result);
        if (st.find(root->val) != st.end()) {
            if (root->left) result.push_back(root->left);
            if (root->right) result.push_back(root->right);
            return NULL;
        }
        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st(to_delete.begin(), to_delete.end());
        vector<TreeNode*> result;
        root = answer(root, st, result);
        // means abhi tk delete nhi hua...
        if (root != NULL) {
            result.push_back(root);
        }

        return result;
    }
};