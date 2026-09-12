class Solution {
public:
    bool dfs(int node,unordered_map<int,vector<int>>&hash,vector<bool>&vis,vector<bool>&vis_path){
        vis[node]=true;
        vis_path[node]=true;
        for(auto&it:hash[node]){
            if(!vis[it]){
                if(dfs(it,hash,vis,vis_path)){
                    return true;
                }
            }
            // iska means cycle hain 
            else if(vis_path[it]){
                return true;
            }
        }
        vis_path[node]=false;
        return false;
    }
    bool canFinish(int N, vector<vector<int>>& nums) {
        unordered_map<int,vector<int>>hash;

        for(int i=0;i<nums.size();i++){
            hash[nums[i][0]].push_back(nums[i][1]);
        }
        vector<bool>vis(N,false);
        vector<bool>vis_path(N,false);
        for(int i=0;i<N;i++){
            if(!vis[i]){
                 if(dfs(i,hash,vis,vis_path)){
                    return false;
                 }
            }
        }
        return true;

    }
};