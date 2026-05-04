class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>>ans;
        // traverse collumn wise 
        for(int i=0;i<matrix.size();i++){
            vector<int>temp;
            for(int j=0;j<matrix[0].size();j++){
                temp.push_back(matrix[j][i]);
            }
            reverse(temp.begin(),temp.end());
            ans.push_back(temp);
        }
        matrix=ans;
    }
};