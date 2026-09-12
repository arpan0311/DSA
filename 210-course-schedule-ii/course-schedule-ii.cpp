class Solution {
public:
    bool dfs(int node,vector<vector<int>>&adj,vector<bool>&vis,vector<bool>&vis_path,queue<int>&q){
        vis[node]=true;
        vis_path[node]=true;
        for(auto&it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,vis_path,q)){
                    return true;
                }
            }
            else if(vis_path[it]){
                return true;
            }
        }
        vis_path[node]=false;
        q.push(node);
        return false;
    }
    vector<int> findOrder(int N, vector<vector<int>>& nums) {
        vector<int>ans;
        vector<bool>vis(N,false);
        vector<bool>path_vis(N,false);  
        vector<vector<int>>adj(N);
        queue<int>q;
        for(int i=0;i<nums.size();i++){
            adj[nums[i][0]].push_back(nums[i][1]);
        }      
        for(int i=0;i<N;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,path_vis,q)){
                    return {};
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};