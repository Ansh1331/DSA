class Solution {
public:
    int helper(int index,int amount, vector<int>& arr, vector<vector<int>>& dp){
        if(amount==0) return 0;
        if(index==0){
            if(arr[0] > amount) return 1e8;
            if(amount % arr[0] == 0 ) return amount/arr[0];
            return 1e8;
        }

        if(dp[index][amount] != -1) return dp[index][amount];
        int nottake= helper(index-1,amount,arr,dp);
        int take=1e8;
        if(arr[index] <= amount){
            take= 1+ helper(index,amount-arr[index],arr,dp);
        }

        return dp[index][amount] = min(nottake,take);
    }

    int coinChange(vector<int>& arr, int amount) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans= helper(n-1,amount,arr,dp);
        return ans>=1e8? -1:ans;
    }
};