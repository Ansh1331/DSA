class Solution {
public:
    int helper(vector<vector<int>> & dp,int i,int j,int m,int n){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int up =helper(dp,i-1,j,m,n);
        int left=helper(dp,i,j-1,m,n);

        return dp[i][j]=up+left;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(dp,m-1,n-1,m,n);
    }
};