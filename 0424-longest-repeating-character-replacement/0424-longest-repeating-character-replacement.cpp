class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        int maxlen=0;
        int maxfreq=0;
        unordered_map<char,int> mpp;
        int n=s.size();

        while(r<n){
            mpp[s[r]]++;
            maxfreq= max(maxfreq, mpp[s[r]]);

            while((r-l+1) -maxfreq>k ){
                mpp[s[l]]--;
                l++;
            } 
            maxlen= max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};