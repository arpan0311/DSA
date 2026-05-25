class Solution {
public:

    bool dfs(int curr,vector<vector<int>>& adj, vector<int>&vis,int colour){
        vis[curr]=colour;
        for(auto&it:adj[curr]){
            if(vis[it]==-1){
                // same colour not bipartite
                if(!dfs(it,adj,vis,colour^1)){
                    return false;
                }
            }
            // same colour not bipartite
            else if(colour==vis[it]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int>vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                // odd length cycle h 
                if(!dfs(i,adj,vis,0)){
                    return false;
                }
            }
        }
    // no odd length cycle 
        return true;
    }
};