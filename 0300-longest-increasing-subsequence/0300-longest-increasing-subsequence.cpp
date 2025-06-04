class Solution {
public:
    int helper(int index,int prev,vector<int>& nums,int n,vector<vector<int>>& dp){
        if(index==n){
            return 0;
        }

        if(dp[index][prev+1] != -1) return dp[index][prev+1];
        int take=0;
        if(prev==-1 || nums[index] > nums[prev]){
            take= 1+ helper(index+1,index,nums,n,dp);
        }           
        int nottake= helper(index+1,prev,nums,n,dp);

        return dp[index][prev+1] = max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return helper(0,-1,nums,n,dp);
    }
};