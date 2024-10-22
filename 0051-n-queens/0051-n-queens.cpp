class Solution {
public:

    void solve(int col,int n,vector<vector<string>> &res, vector<string> &board, vector<int> & lowerdiagnol,vector<int> & leftrow,vector<int> & upperdiagnol){
        if(col==n){
            res.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(lowerdiagnol[row+col]==0 && leftrow[row]==0 && upperdiagnol[n-1 + row-col]==0){
                board[row][col]='Q';
                leftrow[row]=1;
                lowerdiagnol[row+col]=1;
                upperdiagnol[n-1+ row-col]=1;
                solve(col+1,n, res, board, lowerdiagnol, leftrow ,upperdiagnol);
                board[row][col]='.';
                leftrow[row]=0;
                lowerdiagnol[row+col]=0;
                upperdiagnol[n-1+ row-col]=0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n);
        string s(n,'.');

        for(int i=0;i<n;i++){
            board[i]=s;
        }

        vector<int> lowerdiagnol(2*n-1, 0), leftrow(n,0), upperdiagnol(2*n-1, 0);
        solve(0,n, res, board, lowerdiagnol, leftrow ,upperdiagnol);
        return res;
    }
}; 