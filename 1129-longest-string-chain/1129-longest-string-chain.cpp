class Solution {
public:
    bool isContain(string s,string t){
        if(t.size() - s.size() != 1) return false;
        int i=0;
        int j=0;
        while(j<t.size()){
            if(s[i] != t[j]){
                j++;
            }
            else{
                i++;
                j++;
            }
        }
        if(i==s.size() && j==t.size()) return true;
        return false;
    }

    int longestStrChain(vector<string>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end(),[](const string& a,const string &b){
            return a.size() < b.size();
        });
        int maxi=1;
        // int lastindex=0;
        vector<int> dp(n, 1);
        // vector<int> hash(n);
        
        for(int index=0;index<n;index++){
            // hash[index]=index;
            for(int prev=0;prev<index;prev++){
                if(isContain(arr[prev],arr[index]) && 1+dp[prev] > dp[index]){
                    dp[index]=1+dp[prev];
                    // hash[index]=prev;
                }
            }
            if(dp[index] > maxi){
                maxi=dp[index];
                // lastindex=index;
            }
        }
        return maxi;
        // vector<int> temp;
        // temp.push_back(arr[lastindex]);
        // while(lastindex != hash[lastindex]){
        //     lastindex= hash[lastindex];
        //     temp.push_back(arr[lastindex]);
        // }
        // reverse(temp.begin(),temp.end());
        // return temp;
    }
};