class Solution {
public:
    int longestOnes(vector<int>& s, int k) {
        unordered_map<int,int> mpp;
        int res=0;

        int l=0,r=0;
        int n=s.size();
        int zcount=0;

        while(r<n){
            mpp[s[r]]++;
            if(s[r]==0) zcount++;

            while(zcount>k){
                mpp[s[l]]--;
                if(s[l] == 0) zcount--;
                l++;
            }

            res=max(res,r-l+1);
            r++;
        }
        return res;
    }
};