class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int> mpp; // char,freq;
        int l=0;
        int r=0;
        int n=s.size();
        int maxlen=0;
        int maxfreq=0;

        while(r<n){
            mpp[s[r]]++;
            maxfreq=max(maxfreq,mpp[s[r]]);

            while(((r-l+1)-maxfreq)>k){
                mpp[s[l]]--;
                l++;
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }

    // a b a b b
    //
};