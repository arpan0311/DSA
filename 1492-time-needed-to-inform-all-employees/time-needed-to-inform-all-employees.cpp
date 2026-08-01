class Solution {
public:
int max_time=0;
    void dfs( unordered_map<int,vector<int>>&adj,vector<int>& informTime,int curr_id,int time){
        max_time=max(max_time,time);

        for(auto&it:adj[curr_id]){
            dfs(adj,informTime,it,time+informTime[curr_id]);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>>adj;
        // adj list manager to staff
        for(int i=0;i<manager.size();i++){
            // ye to sabka maneger hain isko kya need 
            if(manager[i]==-1){
                continue;
            }
            adj[manager[i]].push_back(i);
        }
        dfs(adj,informTime,headID,0);
        return max_time;
    }
};