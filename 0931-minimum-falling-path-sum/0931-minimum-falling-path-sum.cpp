class Solution {
public:
    // int helper(int row,int col,vector<vector<int>> & matrix, vector<vector<int>> & dp){
    //     if(row== matrix.size()-1){
    //         return matrix[row][col];
    //     }

    //     if(dp[row][col]!=-1) return dp[row][col];
    //     int left=INT_MAX,right=INT_MAX;
    //     int down= helper(row+1,col,matrix,dp);
    //     if(col-1>=0) left=helper(row+1,col-1,matrix,dp);
    //     if(col+1<matrix.size()) right=helper(row+1,col+1,matrix,dp);

    //     return dp[row][col]= matrix[row][col] + min(down,min(left,right));
    // }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp=matrix;
        // int res=INT_MAX;
        for(int row=n-2;row>=0;row--){
            for(int col=0;col<n;col++){
                int left=INT_MAX,right=INT_MAX;
                int down=dp[row+1][col];
                if(col-1>=0) left=dp[row+1][col-1];
                if(col+1<matrix.size()) right=dp[row+1][col+1];

                dp[row][col]= matrix[row][col] + min(down,min(left,right));
            }
        }
        return *min_element(dp[0].begin(), dp[0].end());   
    }
};