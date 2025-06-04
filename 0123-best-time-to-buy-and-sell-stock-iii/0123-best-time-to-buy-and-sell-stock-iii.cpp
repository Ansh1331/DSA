class Solution {
public:
    int helper(int i, int buy,int cap, vector<int>&prices, vector<vector<vector<int>>>& dp){
        if(i==prices.size()) return 0;
        if(cap==0) return 0;

        if(dp[i][buy][cap] != -1) return dp[i][buy][cap];
        if(buy){
            dp[i][buy][cap]= max( -prices[i] + helper(i+1,0,cap,prices,dp) , //bought
                        helper(i+1,1,cap,prices,dp));            //not bought
        }
        else{
            dp[i][buy][cap]= max( +prices[i] + helper(i+1,1,cap-1,prices,dp), //sold
                        helper(i+1,0,cap,prices,dp));             //not sold
        }
        return dp[i][buy][cap];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp (n, vector<vector<int>>(2,vector<int> (3,-1)));
        return helper(0,1,2,prices,dp);
    }
};