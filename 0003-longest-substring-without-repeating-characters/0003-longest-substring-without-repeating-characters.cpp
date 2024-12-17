class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen=0;
        map<char,int> mpp; // char,index
        int n=s.size();
        int l=0;
        int r=0;

        while(r<n){
            if(mpp.find(s[r]) != mpp.end() && mpp[s[r]]>=l){
                l= mpp[s[r]]+1;
            }
            int len=r-l+1;
            maxlen=max(maxlen,len);
            mpp[s[r]]=r;
            r++;
        }
        return maxlen;
    }
};