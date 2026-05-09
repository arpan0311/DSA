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
string s="";
    string solve(TreeNode* subRoot){

        if(!subRoot){
            return "N";
        }

        s=to_string(subRoot->val)+","+solve(subRoot->left)+","+solve(subRoot->right);

        return s;
    }
     string solve1(TreeNode* subRoot,unordered_map<string,int>&hash){

        if(!subRoot){
            return "N";
        }

        string s=to_string(subRoot->val)+","+solve1(subRoot->left,hash)+","+solve1(subRoot->right,hash);
        hash[s]++;
        return s;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
          
        string s="";
        string ans=solve(subRoot);//orignal 
        unordered_map<string,int>hash;
        solve1(root,hash);
        if(hash.count(ans)){
            return true;
        }
        return false;
    }
};

