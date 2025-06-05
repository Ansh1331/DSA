class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> count(n,1);
        int maxi=0;
        for(int curr=0;curr<n;curr++){
            for(int prev=0;prev<curr;prev++){
                if (nums[curr] > nums[prev]) {
                    if (dp[prev] + 1 > dp[curr]) {
                        dp[curr] = dp[prev] + 1;
                        count[curr] = count[prev]; // reset
                    } else if (dp[prev] + 1 == dp[curr]) {
                        count[curr] += count[prev]; // accumulate
                    }
                }
            }
            maxi=max(maxi,dp[curr]);
        }
        int res=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi){
                res += count[i];
            }
        }
        return res;
    }
    
};