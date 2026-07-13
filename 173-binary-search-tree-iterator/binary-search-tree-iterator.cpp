class BSTIterator {
public:
    void inorder(TreeNode* root, vector<int>& ans) {
        if (!root) {
            return;
        }
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    vector<int> answer;
    int i = 0;
    BSTIterator(TreeNode* root) { inorder(root, answer); }

    int next() {
        int val = answer[i];
        i++;
        return val;
    }

    bool hasNext() {
        if (i >= answer.size()) {
            return false;
        }
        return true;
    }
};