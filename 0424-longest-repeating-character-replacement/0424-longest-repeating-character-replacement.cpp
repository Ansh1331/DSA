class Solution {
public:
    int characterReplacement(string s, int k) {
        int res=0;
        int maxfreq=0;
        map<int,int> mpp;
        int l=0,r=0;

        while(r<s.size()){
            mpp[s[r]]++;

            maxfreq=max(maxfreq,mpp[s[r]]);
            int len=r-l+1;
            if(len-maxfreq > k){
                mpp[s[l]]--;
                if(mpp[s[l]]==0) mpp.erase(s[l]);
                l++;
            }

            res=max(res,r-l+1);
            r++;
        }

        return res;

    }
};