class Solution {
public:
    int helper(int index, int buy, vector<int>& arr, vector<vector<int>>& dp){
        if(index==arr.size()) return 0;

        if(dp[index][buy] != -1 ) return dp[index][buy];

        if(buy){
            dp[index][buy] =max(-arr[index] + helper(index+1,0,arr,dp), 
                                helper(index+1, buy,arr,dp));
        }
        else{
            dp[index][buy] = max(arr[index] + helper(index+1,1,arr,dp), helper(index+1,0,arr,dp));
        }

        return dp[index][buy];
    }

    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return helper(0,1,arr,dp); //1 -> buy
    }
};