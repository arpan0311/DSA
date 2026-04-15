class Solution {
private:
bool isvalid(vector<vector<char>>&board,int row,int col,char ch){
    for(int i=0;i<=8;i++){
         
        if(board[i][col]==ch){
            return false;
        }
        if(board[row][i]==ch){
            return false;
        }
        // most importent thing
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==ch){
            return false;
        }
    }
    return true;
    
}
bool solve(vector<vector<char>>&board){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
    // merko khali mil gaya....
            if(board[i][j]=='.'){
    // check which digit can be filled
    for(char ch='1';ch<='9';ch++){
        if(isvalid(board,i,j,ch)){
            board[i][j]=ch;
            if(solve(board)==true){
                return true;
            }
            else{
                board[i][j]='.';
            }
        }
    }
    // try all number from 1 to 9 but none of them make sense for this that's why we return false at the end...
     return false;
            }
        }
    }
    return true;
}
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};