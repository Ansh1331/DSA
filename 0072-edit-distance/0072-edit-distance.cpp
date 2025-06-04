class Solution {
public:
    int helper(int i,int j,string& s,string& t, vector<vector<int>> &dp){
        if(j<0) return i+1;
        if(i<0) return j+1;

        if(dp[i][j]!= -1) return dp[i][j];
        if(s[i] == t[j]){
            return dp[i][j]= helper(i-1,j-1,s,t,dp);
        }
        else{
            return dp[i][j]= 1+ min(helper(i,j-1,s,t,dp) , min(helper(i-1,j,s,t,dp) , helper(i-1,j-1,s,t,dp) ) );
        }                       //insert                     //delete                //replace
    }

    int minDistance(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n==0 && m==0) return 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return helper(n-1,m-1,s,t,dp);
    }
};