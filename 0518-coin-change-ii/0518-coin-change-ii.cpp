class Solution {
public:
    int helper(int index, int amount, vector<vector<int>>& dp, vector<int>& arr){
       if (index == 0) {
    return (amount % arr[0] == 0) ? 1 : 0;
}

        // if(arr[index] > amount) return 0;

        if(dp[index][amount]!=-1) return dp[index][amount];

        int nottake= helper(index-1,amount,dp,arr);
        int take=0;
        if(arr[index] <= amount){
            take= helper(index,amount-arr[index],dp,arr);
        }

        return dp[index][amount]= take + nottake;
    }


    int change(int amount, vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return helper(n-1,amount,dp,arr);
    }
};