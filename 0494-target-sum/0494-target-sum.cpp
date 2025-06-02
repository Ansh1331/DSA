class Solution {
public:

    int helper(int index,int target,vector<int>& arr,vector<vector<int>> & dp){
        if (index == 0) {
            if (target == 0 && arr[0] == 0) return 2;  // Two ways: include or exclude 0
            if (target == 0 || arr[0] == target) return 1;
            return 0;
        }
        
        if(dp[index][target]!= -1) return dp[index][target];
        int  nottake=helper(index-1,target,arr,dp);
        int take=0;
        if(arr[index] <= target) take=helper(index-1,target-arr[index],arr,dp);
        
        return dp[index][target]=take+nottake;
        
    }
  
    int perfectSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return helper(n-1,target,arr,dp);
        
    }
    
    int countPartitions(vector<int>& arr, int d) {
        int totalsum= accumulate(arr.begin(),arr.end(),0);
        if ((totalsum - d) < 0 || (totalsum - d) % 2 != 0) return 0;
        int s = (totalsum - d) / 2;
        
        return perfectSum(arr,s);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums,target);
    }
};