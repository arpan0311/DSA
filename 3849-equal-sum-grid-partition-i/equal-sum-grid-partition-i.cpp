class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long sum=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                sum+=grid[i][j];
            }
        }
        long long sum1=0;
         for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                sum1+=grid[i][j];
            }
            if(sum-sum1==sum1){
                return true;
            }
        }
        sum1=0;
        for(int i=0;i<grid[0].size();i++){
            for(int j=0;j<grid.size();j++){
                sum1+=grid[j][i];
            }
            if(sum-sum1==sum1){
                return true;
            }
        }

        return false;
    }
};