class Solution {
public:
    bool isPossible(vector<vector<char>> & board,int row,int col,char ch){
        for(int i=0;i<9;i++){
            if(board[i][col]==ch){
                return false;
            }
            if(board[row][i]==ch){
                return false;
            }
            if(board[3*(row/3) + i/3][3*(col/3) + i%3]==ch){
                return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>> & board){
        int row=board.size();
        int col=board[0].size();

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]=='.'){
                    for(char ch='1' ;ch<='9';ch++){
                        if(isPossible(board,i,j,ch)){
                            board[i][j]=ch;

                            if(solve(board)==true){
                                return true;
                            }
                            else{
                                board[i][j]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

};