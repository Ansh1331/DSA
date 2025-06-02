class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1)); 
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0){
                dp[0][i] = i/coins[0];
            }
            else dp[0][i]=1e8;
        }

        for(int index=1;index<n;index++){
            for(int target=0;target<=amount;target++){
                int nottake= dp[index-1][target];
                int take=1e8;
                if(coins[index] <= target) take=1+ dp[index][target-coins[index]];

                dp[index][target]= min(nottake,take);
            }
        }
        int ans=dp[n-1][amount];
        return ans>=1e7 ? -1:ans;

    }
};