class Solution {
public:
     bool helper(int index,int sum,vector<int>& arr, vector<vector<int>>& dp){
        if(sum==0 ) return true;
        if(index==0){
            return arr[0]==sum;
        }
        if(dp[index][sum] != -1) return dp[index][sum];
        bool nottake= helper(index-1,sum,arr,dp);
        bool take=false;
        if(arr[index] <= sum){
            take= helper(index-1,sum-arr[index],arr,dp);
        }
        return dp[index][sum]=take || nottake;
    }

    bool canPartition(vector<int>& nums) {
        int sum =accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1) return false;
        int target=sum/2;
        vector<vector<int>> dp(nums.size(),vector<int> (target+1,-1));
        return helper(nums.size()-1,target,nums,dp);
    }
};