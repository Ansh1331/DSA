class Solution {
public:
    int helper(int i,int j1, int j2,  vector<vector<vector<int>>>& dp,int n,int m,vector<vector<int>>& grid){
        if(j1<0 || j1>m-1 || j2<0 || j2>m-1) return -1e8;
        if(i==n-1) {
            if(j1!=j2) return grid[i][j1] + grid[i][j2];
            else return grid[i][j1];
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int maxi=-1e8;
        for(int delr=-1 ; delr<=1; delr++){
            for(int delc=-1;delc <= 1 ; delc++){
                int value=0;
                if(j1!=j2) value= grid[i][j1] + grid[i][j2];
                else value= grid[i][j1];
                value += helper(i+1, j1+delr, j2+delc, dp,n,m,grid);
                maxi= max(maxi,value);
            }
        }
        return dp[i][j1][j2]= maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp (n,vector<vector<int>> (m,vector<int> (m,-1)));
        return helper(0,0,m-1,dp,n,m,grid);
        //0,0 robot-1, 0,m-1 robot-2

    }
};