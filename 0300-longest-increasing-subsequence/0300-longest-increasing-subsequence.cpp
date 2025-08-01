class Solution {
public:
    int helper(int index, int prev,vector<vector<int>>& dp, vector<int>& arr){
        if(index==arr.size()) return 0;

        if(dp[index][prev+1] != -1) return dp[index][prev+1];
        int take=0;
        if(prev==-1 || arr[prev] < arr[index]){
            take= 1+ helper(index+1,index,dp,arr);
        }
        int nottake= helper(index+1,prev,dp,arr);

        return dp[index][prev+1] = max(take,nottake);
    }

    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return helper(0,-1,dp,arr);
    }
};