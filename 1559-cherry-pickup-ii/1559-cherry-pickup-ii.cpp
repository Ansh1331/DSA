class Solution {
public:
    int helper(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp,int n,int m){
        if(j1<0 || j2<0 || j1>m-1 || j2>m-1){
            return -1e8;
        }   
        if(i == n-1){
            if(j1==j2){
                return grid[i][j1];
            }
            else{
                return grid[i][j1] + grid[i][j2];
            }
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int maxi=-1e8;
        for(int delrow=-1; delrow<=1;delrow++){
            for(int delcol=-1; delcol<=1;delcol++){
                int value=0;
                if(j1!=j2){
                value= grid[i][j1] + grid[i][j2];
                }   
                else value=grid[i][j1];
                value+= helper(i+1,j1+delrow,j2+delcol,grid,dp,n,m);
                maxi= max(maxi,value);
            }
        }
        return dp[i][j1][j2]= maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int> (m,-1)));

        return helper(0,0,m-1,grid,dp,n,m);
    }
};