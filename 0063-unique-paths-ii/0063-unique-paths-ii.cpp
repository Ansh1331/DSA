class Solution {
public:
    int helper(vector<vector<int>>& grid,int n,int m,vector<vector<int>> &dp){
        if(n==0 && m==0){
            if(grid[0][0] == 0) return 1;
            else return 0;
        } 
        if(n<0 || m<0 ) return 0;
        if(grid[n][m] == 1) return 0;
        if(dp[n][m] != -1) return dp[n][m];

        int up= helper(grid,n-1,m,dp);
        int left= helper(grid,n,m-1,dp);

        return dp[n][m]= up+left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        //if(n==1 && m==1 && ) return 0;
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return helper(grid,n-1,m-1,dp);
    }
};