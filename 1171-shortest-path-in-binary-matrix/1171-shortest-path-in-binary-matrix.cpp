class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dis(n,vector<int>(n,INT_MAX));
        // if(n==1) return 1;
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;

        dis[0][0]=1;
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});

        while(!q.empty()){
            auto it=q.front(); 
            q.pop();
            int dist=it.first;
            int row=it.second.first;
            int col=it.second.second;

            for(int delrow=-1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    int nrow = row+delrow;
                    int ncol= col+delcol;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==0 && dist+1<dis[nrow][ncol]){
                        dis[nrow][ncol]=dist+1;
                        q.push({dist+1,{nrow,ncol}});
                    }
                }
            }
        }
        if(dis[n-1][n-1] == INT_MAX) return -1;
        return dis[n-1][n-1];
    }
};