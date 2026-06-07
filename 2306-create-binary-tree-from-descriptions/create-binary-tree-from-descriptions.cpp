class Solution {
public:
    TreeNode* formBinaryTree(unordered_map< int, vector<pair<int, int>>> &hash,
                            TreeNode* &root) {
      
        sort(hash[root->val].begin(),
             hash[root->val].end());
              for (auto& it : hash[root->val]) {
            if (it.second == 1) {
                root->left = new TreeNode(it.first);
                 formBinaryTree(hash, root->left);
            } else {
                root->right = new TreeNode(it.first);
                 formBinaryTree(hash,  root->right);
            }
        }

        return root;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& nums) {
        unordered_map < int, vector<pair<int, int>>> hash;

        for (int i = 0; i < nums.size(); i++) {
        hash[nums[i][0]].push_back({nums[i][1], nums[i][2]});
        }
        // find root;
        unordered_map<int,int> root1;

        for (int i = 0; i < nums.size(); i++) {
            root1[nums[i][1]]++;
        }
        int root2 = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (root1.find(nums[i][0]) == root1.end()) {
                root2 = nums[i][0];
                break;
            }
        }

        // ab mere pass root hai aur hash map h ab mai bna
        if(root2==-1){
            return nullptr;
        }
          TreeNode* root = new TreeNode(root2);
        return formBinaryTree(hash,root);
    }
};