class Solution {
public:
    void solve(vector<pair<int, int>>& answer, vector<vector<int>>& mat) {
        for (auto& it : answer) {
            int i = it.first;
            int j = it.second;
            for (int k = 0; k < mat.size(); k++) {
                mat[k][j] = 0;
            }
            for (int k = 0; k < mat[0].size(); k++) {
                mat[i][k] = 0;
            }
        }
    }    

        void setZeroes(vector<vector<int>> & matrix) {
            
            set<int>row,col;
            for (int i = 0; i < matrix.size(); i++) {
                for (int j = 0; j < matrix[0].size(); j++) {
                    if (matrix[i][j] == 0) {
                      
                        row.insert(i);
                        col.insert(j);
                       
                    }

                }
            }
            for(auto&it:row){
                for(int j=0;j<matrix[0].size();j++){
                    matrix[it][j]=0;
                }
            }
            for(auto&it:col){
                for(int j=0;j<matrix.size();j++){
                    matrix[j][it]=0;
                }
            }
        }
    };