class Solution {
public:
    void bfs(int i,int j,vector<vector<int>>& vis,int n,int m,vector<vector<char>>& grid){
        queue<pair<int,int>> q;
        vis[i][j]=1;
        q.push({i,j});
        vector<pair<int,int>> directions={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int r=it.first;
            int c=it.second;

            for(auto it:directions){
                int nrow=r+it.first;
                int ncol=c+it.second;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        } 
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    bfs(i,j,vis,n,m,grid);
                }
            }
        }
        return count;
    }
};