class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0;
        int l=0;
        int r=0;
        map<char,int>mpp;
        int n=s.size();
        while(r<n){
            char ch= s[r];
            if(mpp.find(ch) != mpp.end()){
                mpp.erase(s[l]);
                l++;
            }
            else{
                mpp[ch]++;
                r++;
                res= max(res, r-l);
            }
        }
        return res;
    }
};