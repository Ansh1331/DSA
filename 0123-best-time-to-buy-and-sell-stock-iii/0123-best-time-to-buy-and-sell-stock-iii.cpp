class Solution {
public:
    int helper(int index, int buy,int cap, vector<int>& arr, vector<vector<vector<int>>>& dp){
        if(index==arr.size()) return 0;
        if(cap==0) return 0;

        if(dp[index][buy][cap] != -1 ) return dp[index][buy][cap];

        if(buy){
            if(cap>0){
                dp[index][buy][cap] =max(-arr[index] + helper(index+1,0,cap,arr,dp), 
                                helper(index+1, buy,cap,arr,dp));
            }
        }
        else{
            dp[index][buy][cap] = max(arr[index] + helper(index+1,1,cap-1,arr,dp), 
                                helper(index+1,0,cap,arr,dp));
        }

        return dp[index][buy][cap];
    }
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        // vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return helper(0,1,2,arr,dp); //1 -> buy
    }
};