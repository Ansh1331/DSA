class Solution {
public:
    int helper(vector<int>& nums,int n,vector<int>& dp){
        if(n==0) return dp[0];
        if(dp[n]!=-1) return dp[n];

        int pick=nums[n];
        if(n>1){
            pick= nums[n] + helper(nums,n-2,dp);
        }
        int notpick= helper(nums,n-1,dp);

        return dp[n]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        dp[0]=nums[0];
        return helper(nums,n-1,dp);
    }
};