class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dist (n,vector<int> (n,1e9));
        queue<pair<int, pair<int,int>>> q;
        q.push({1,{0,0}});
        dist[0][0]=1;
        if(grid[0][0]== 1 || grid[n-1][n-1]==1 ) return -1;

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int dis=it.first;
            int row=it.second.first;
            int col=it.second.second;

            for(int delrow=-1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    int nrow=row+delrow;
                    int ncol=col+delcol;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==0 && dis+1 < dist[nrow][ncol]){
                        dist[nrow][ncol]=dis+1;
                        if(nrow==n-1 && ncol==n-1) return dis+1;
                        q.push({dis+1,{nrow,ncol}});
                    }
                }
            }
        }
        // return -1;
        if(dist[n-1][n-1] == 1e9) return -1;
        return dist[n-1][n-1];

    }
};