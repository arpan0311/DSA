/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& hash) {
        if (!root) {
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
                
                TreeNode* it = q.front();
                q.pop();
                if (it->left) {
                    hash[it->left] = it;
                    q.push(it->left);
                }
                if (it->right) {
                    hash[it->right] = it;
                    q.push(it->right);
                }
            }
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        // now I have parent pointer...
        solve(root, parent);

        queue < pair<TreeNode*, int>>q;
        unordered_map<TreeNode*, int> hash;
        hash[target] = 1;
        
        q.push({target, 0});

        while (!q.empty()) {
              
            if (q.front().second == k) {
                break;
            }
            int dis=q.front().second;
              dis++;
            TreeNode* node = q.front().first;
            q.pop();
            // just unvisited hona tha na... and exist
            if (node->left && hash.find(node->left) == hash.end()) {
                q.push({node->left, dis});
                hash[node->left]=1;
            }

            if (node->right && hash.find(node->right) == hash.end()) {
                q.push({node->right, dis});
                hash[node->right]=1;
            }

            if (parent[node] && hash.find(parent[node]) == hash.end()) {
                q.push({parent[node], dis});
                hash[parent[node]]=1;
            }
        }

        vector<int> answer;

        while (!q.empty()) {
            answer.push_back(q.front().first->val);
            q.pop();
        }
        return answer;
    }
};