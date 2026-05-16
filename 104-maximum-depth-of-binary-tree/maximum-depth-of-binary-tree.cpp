
class Solution {
public:
    void solve(TreeNode* root,int cnt,int &maxi){
        if(!root){
            maxi=max(maxi,cnt);
            return;
        }

            solve(root->left,cnt+1,maxi);
        

            solve(root->right,cnt+1,maxi);
        
    }

    int maxDepth(TreeNode* root) {

        int cnt=0,maxi=0;
        solve(root,cnt,maxi);
        return maxi;
    }
};