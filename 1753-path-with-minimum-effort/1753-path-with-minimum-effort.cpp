class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& height) {
        int n=height.size();
        int m=height[0].size();
        vector<vector<int>> dist (n,vector<int> (m,1e9));
        priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int,int>>>,greater<pair<int, pair<int,int>>>> q;
        q.push({0,{0,0}});
        dist[0][0]=0;
     //   if(height[0][0]== 1 || height[n-1][n-1]==1 ) return -1;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        while(!q.empty()){
            auto it=q.top();
            q.pop();
            int effort=it.first;
            int row=it.second.first;
            int col=it.second.second;

            if(row==n-1 && col==m-1) return effort;

            for(int i=0;i<4;i++){
                    int nrow=row+delrow[i];
                    int ncol=col+delcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                        int diff= abs(height[nrow][ncol] - height[row][col]);
                        int neweffort=max(effort,diff);

                        if(neweffort < dist[nrow][ncol]){
                            dist[nrow][ncol]=neweffort;
                            q.push({neweffort,{nrow,ncol}});
                        }
                    }
            }
        }
        return 0;
    }
};