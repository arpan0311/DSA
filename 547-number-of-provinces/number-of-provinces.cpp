class Solution {
public:
    void bfs(vector<vector<int>>&adj,vector<int>&vis,int node){
        vis[node]=1;
      
        for(auto&it:adj[node]){
            if(!vis[it]){
                bfs(adj,vis,it);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& mat) {
        int n=mat.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1&&i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
   
        vector<int> vis(n, 0); 
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                bfs(adj,vis,i);
            }
        }
        return cnt;
    }
};