class Solution {
public:
    int helper(int i, int buy, vector<int>&prices, vector<vector<int>>& dp){
        if(i==prices.size()) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];
        if(buy){
            dp[i][buy]= max( -prices[i] + helper(i+1,0,prices,dp) , //bought
                        helper(i+1,1,prices,dp));            //not bought
        }
        else{
            dp[i][buy]= max( +prices[i] + helper(i+1,1,prices,dp), //sold
                        helper(i+1,0,prices,dp));             //not sold
        }
        return dp[i][buy];
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int> (2,-1));
        return helper(0,1,prices,dp);
    }
};