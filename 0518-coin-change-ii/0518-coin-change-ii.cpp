class Solution {
public:
    int helper(int index,vector<int>& coins,int amount,vector<vector<int>>& dp){
      //  if(amount==0) return 0;
        if(index==0) {
            //if(coins[0] > amount) return 0;
            return (amount % coins[0] == 0) ? 1:0;
        }

        if(dp[index][amount] != -1) return dp[index][amount];
        int nottake= helper(index-1,coins,amount,dp);
        int take=0;
        if(coins[index] <= amount) take=helper(index,coins,amount-coins[index],dp);

        return dp[index][amount]= nottake + take;
    }

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return helper(n-1,coins,amount,dp);
    }
};