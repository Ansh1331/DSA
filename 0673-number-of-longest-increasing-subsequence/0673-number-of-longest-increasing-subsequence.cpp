class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n+1,1);
        vector<int> count(n+1,1);
        int maxi=1;
        int countt=0;

        for(int index=0;index<n;index++){
            for(int prev=0;prev<index;prev++){
                if(arr[prev] < arr[index]){
                    if(dp[prev] + 1 > dp[index]){
                        dp[index]=dp[prev]+1;
                        count[index]=count[prev];
                    }
                    else if(dp[prev] +1 == dp[index]){
                        count[index]+= count[prev];
                    }
                }
            }
            maxi=max(maxi,dp[index]);
        }

        for(int i=0;i<n;i++){
            if(dp[i] == maxi){
                countt+= count[i];
            }
        }
        return countt;
    }
};