class Solution {
public:
    int helper(vector<int>&dp, int index){
        if(index==0 || index==1) return 1;

        if(dp[index]!=-1) return dp[index];

        int one= helper(dp,index-1);
        int two=0;
        if(index>1){
            two=helper(dp,index-2);
        }

        return dp[index]=one+two;
    }

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return helper(dp,n);
    }
};