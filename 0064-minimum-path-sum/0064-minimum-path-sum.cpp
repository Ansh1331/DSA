class Solution {
public:
    int helper(int m,int n,vector<vector<int>> & dp,vector<vector<int>>& grid){
        if(m==0 && n==0) return grid[0][0];
        
        if(m<0 || n<0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];

        //up
        int up=INT_MAX;
        if(m>0){
            up=helper(m-1,n,dp,grid);
        }

        //left
        int left=INT_MAX;
        if(n>0){
            left=helper(m,n-1,dp,grid);
        }

        return dp[m][n]=grid[m][n]+ min(up,left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return helper(m-1,n-1,dp,grid);
        
    }
};