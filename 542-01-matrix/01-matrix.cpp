class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>>solve(m,vector<int>(n,0));
         vector<vector<bool>>vis(m,vector<bool>(n,false));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=true;
                }
            }
        }
        while(!q.empty()){
            int curr_row=q.front().first.first;
            int curr_col=q.front().first.second;
            int dis=q.front().second;
            solve[curr_row][curr_col]=dis;

            int row[]={1,0,-1,0};
            int col[]={0,1,0,-1};
            q.pop();
            for(int k=0;k<4;k++){
                int i=curr_row+row[k];
                int j=curr_col+col[k];
                if(i<m&&i>=0&&j<n&&j>=0&&!vis[i][j]){
                    vis[i][j]=true;
                    q.push({{i,j},dis+1});
                }
            }
        }
        return solve;
    }
};