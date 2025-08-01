class Solution {
public:
    bool helper(int i,int j,string& s,string& t,vector<vector<int>>& dp){
        if(j<0 && i<0) return true;
        if(j<0 && i>=0) return false;
        if(i<0 && j>=0){
            for(int k=0;k<=j;k++){
                if(t[k] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j] || t[j]=='?'){
            return dp[i][j]=helper(i-1,j-1,s,t,dp);
        }
        else if(t[j]=='*'){
            return dp[i][j]=helper(i-1,j,s,t,dp) || helper(i,j-1,s,t,dp);
        }
        else{
            return false;
        }

    }

    bool isMatch(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return helper(n-1,m-1,s,t,dp);
    }
};