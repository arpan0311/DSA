class Solution {
public:
void solve(int i,vector<vector<int>>&answer){
    for(int j=0;j<=i;j++){
        if(j==0){
            answer[i].push_back(1);
            continue;
        }
        else if(j==i){
            answer[i].push_back(1);
            continue;
        }
        else{
            int cnt=answer[i-1][j-1]+answer[i-1][j];
            answer[i].push_back(cnt);
        }

    }
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>answer(numRows);
        for(int i=0;i<numRows;i++){
            solve(i,answer);
        }
        return answer;
    }
};