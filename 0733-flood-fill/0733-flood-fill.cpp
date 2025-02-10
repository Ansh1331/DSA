class Solution {
private:
    void bfs(vector<vector<int>>& image,vector<vector<int>>& vis,int sr,int sc,int color,int ori,int n,int m,int delrow[],int delcol[]){
        vis[sr][sc]=1;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc]=color;

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && image[nrow][ncol]==ori && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    image[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        int ori=image[sr][sc];
        if(ori!=color){
            bfs(image,vis,sr,sc,color,ori,n,m,delrow,delcol);
        }

        return image;
    }
};