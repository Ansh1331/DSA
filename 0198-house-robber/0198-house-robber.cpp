class Solution {
public:
     int helper(vector<int>&dp, int i,vector<int>&arr){
        if(i==0){
            return arr[0]; 
        }

        if(dp[i]!=-1) return dp[i];

        int nottake=helper(dp,i-1,arr);
        int take=0;
        if(i>1){
            take= arr[i]+helper(dp,i-2,arr);
        }
        return dp[i]=max(take,nottake);
    }

    int rob(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n+1,-1);
        return helper(dp,n-1,arr);
    }
};