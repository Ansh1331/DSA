class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0;
        int n=s.size();
        int res=0;
        map<char,int> mpp; //char,index
        while(r<n){
            if(mpp.find(s[r])!= mpp.end() && l<= mpp[s[r]]){
                l= mpp[s[r]]+1;
            }
            int len=r-l+1;
            res=max(res,len);
            mpp[s[r]]=r;
            r++;
        }
        return res;
    }
};