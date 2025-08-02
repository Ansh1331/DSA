class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n=arr.size();
        int maxi=1;
        int lastindex=0;
        sort(arr.begin(),arr.end());
        vector<int> dp(n, 1);
        vector<int> hash(n);
        
        for(int index=0;index<n;index++){
            hash[index]=index;
            for(int prev=0;prev<index;prev++){
                if((arr[prev]%arr[index]==0 || arr[index]%arr[prev]==0) && 1+dp[prev]>dp[index]){
                    dp[index]=1+dp[prev];
                    hash[index]=prev;
                }
            }
            if(dp[index] > maxi){
                maxi=dp[index];
                lastindex=index;
            }
        }
        
        vector<int> temp;
        temp.push_back(arr[lastindex]);
        while(lastindex != hash[lastindex]){
            lastindex= hash[lastindex];
            temp.push_back(arr[lastindex]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};