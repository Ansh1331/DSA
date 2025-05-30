class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> vis(n,vector<int> (n,0));
        vis[0][0]=1;
        int res=grid[0][0];
        //dis , row, col
        pq.push({res,{0,0}});

        int delrow[]={1,0,-1,0};
        int delcol[]={0,1,0,-1};
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int time=it.first;
            int row=it.second.first;
            int col=it.second.second;
            if(row==n-1 && col==n-1){
                return time;
            }
            for(int i=0;i<4;i++){
                int nrow=row + delrow[i];
                int ncol=col + delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && vis[nrow][ncol]==0){
                    vis[nrow][ncol]=1;
                    int newtime= max(time,grid[nrow][ncol]);
                    pq.push({newtime,{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};