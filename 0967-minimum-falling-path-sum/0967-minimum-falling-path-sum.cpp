class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp = matrix; // Start with last row same as matrix

        for (int row = n - 2; row >= 0; --row) {
            for (int col = 0; col < n; ++col) {
                int down = dp[row + 1][col];
                int left = (col > 0) ? dp[row + 1][col - 1] : INT_MAX;
                int right = (col < n - 1) ? dp[row + 1][col + 1] : INT_MAX;

                dp[row][col] = matrix[row][col] + min({down, left, right});
            }
        }

        // Return min from the top row
        return *min_element(dp[0].begin(), dp[0].end());
    }
};
