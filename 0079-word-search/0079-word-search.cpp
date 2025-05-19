class Solution {
public:
    bool helper(int n,int m,int index,vector<vector<char>>&board,string word,int i,int j){
        if(index==word.size()){
            return true;
        }
        if(i<0 || j<0 || i==n || j==m || board[i][j]!=word[index]) return false;

        char ch=board[i][j];
        board[i][j]='#';

        bool op1=helper(n,m,index+1,board,word,i+1,j);
        bool op2=helper(n,m,index+1,board,word,i,j+1);
        bool op3=helper(n,m,index+1,board,word,i,j-1);
        bool op4=helper(n,m,index+1,board,word,i-1,j);

        board[i][j]=ch;
        return op1||op2||op3||op4;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        int index=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(helper(n,m,index,board,word,i,j)){
                        return true;
                    };
                }
            }
        }
        return false;
    }
};