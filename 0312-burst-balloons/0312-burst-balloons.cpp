class Solution {
public:
    int helper(int i,int j,vector<int>& arr,vector<vector<int>>& dp){
        if(i>j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int maxi=-1e8;
        for(int k=i ; k<=j; k++){
            int steps= arr[i-1] * arr[k] * arr[j+1] + helper(i,k-1,arr,dp)
                        +helper(k+1,j,arr,dp);
            if(steps>maxi) maxi=steps;
        }
        return dp[i][j]= maxi;
    }

    int maxCoins(vector<int>& arr) {
        int n=arr.size();
        arr.push_back(1);
        arr.insert(arr.begin(),1);
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));   
        return helper(1,n,arr,dp);
    }
};