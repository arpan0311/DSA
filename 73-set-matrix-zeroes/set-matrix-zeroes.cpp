class Solution {
public:
    void solve(int i,int j,vector<vector<int>>&mat){
        for(int k=0;k<mat.size();k++){
            mat[k][j]=0;
        }
        for(int k=0;k<mat[0].size();k++){
            mat[i][k]=0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>>answer(matrix.begin(),matrix.end());
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    solve(i,j,answer);
                }
            }
        }
        matrix=answer;
    }
};