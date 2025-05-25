class Solution {
public:
    void bfs(int i,int j,vector<vector<int>>& vis,int n,int m,vector<vector<int>>& grid){
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
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        } 
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        int freshcount=0;
        int mins=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    freshcount++;
                }
            }
        }

        vector<pair<int,int>> directions={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty() && freshcount>0){
            int size=q.size();
            mins++;

            for(int i=0;i<size;i++){
                auto it=q.front();
                q.pop();
                int row=it.first;
                int col=it.second;

                for(auto it:directions){
                    int nrow=row+it.first;
                    int ncol=col+it.second;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1){
                        grid[nrow][ncol]=2;
                        q.push({nrow,ncol});
                        freshcount--;
                    }
                }   
            }
        }

        return freshcount==0? mins:-1;
    }
};