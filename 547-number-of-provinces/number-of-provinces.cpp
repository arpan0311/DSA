class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj,vector<int>&vis){
        vis[node]=1;
        for(auto&it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& is) {
        // I have to count how many group is there(undirected graph)
        int n=is.size();
        int cnt=0;
        vector<int>vis(n+1,0);
        vector<vector<int>> adj(n+1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(is[i][j] == 1&&i!=j) {
                adj[i].push_back(j);
                // adj[j].push_back(i);
            }
        }
    }

    // now I have adj list 
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adj,vis);
            }
        }
        return cnt;
    }
};