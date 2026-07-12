class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == NULL) {
                s += "#,";
                continue;
            }

            s += to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return NULL;

        stringstream ss(data);
        string str;

        getline(ss, str, ',');
        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // left
            if (!getline(ss, str, ',')) break;
            if (str == "#") {
                node->left = NULL;
            } else {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }

            // right
            if (!getline(ss, str, ',')) break;
            if (str == "#") {
                node->right = NULL;
            } else {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }

        return root;
    }
};