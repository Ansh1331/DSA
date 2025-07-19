class Solution {
public:
    int helper(int n,vector<int>& dp,vector<int>& arr){
        if(n==0 || n<0) return arr[0];
        if(dp[n]!=-1) return dp[n];
        
        //rob
        int pick= arr[n];
        if(n>1){
            pick= arr[n] + helper(n-2,dp,arr);
        }
        //skip
        int skip= helper(n-1,dp,arr);
        
        return dp[n]=max(pick,skip);
    }

    int rob(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n+1,-1);
        return helper(n-1,dp,arr);
    }
};