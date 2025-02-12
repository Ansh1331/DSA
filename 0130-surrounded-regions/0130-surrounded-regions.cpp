class Solution {
private:
    void dfs(int row,int col,vector<vector<char>>& board,vector<vector<int>>& vis){
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        vis[row][col]=1;
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                dfs(nrow,ncol,board,vis);
            }
        }
    }
    
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        //Traverse rows
        for(int j=0;j<m;j++){
            if(!vis[0][j] && board[0][j]=='O'){
                dfs(0,j,board,vis);
            }
            if(!vis[n-1][j] && board[n-1][j]=='O'){
                dfs(n-1,j,board,vis);
            }
        }

        //Traverse cols
        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,board,vis);
            }
            if(!vis[i][m-1] && board[i][m-1]=='O'){
                dfs(i,m-1,board,vis);
            }
        }

        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col]){
                    board[row][col]='X';
                }
            }
        }
    }
};