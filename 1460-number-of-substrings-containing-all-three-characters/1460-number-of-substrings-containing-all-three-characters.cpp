class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0;
        int r=0;
        int res=0;
        int n=s.size();
        unordered_map<char,int> mpp;

        while(r<n){
            mpp[s[r]]++;

            while(mpp.size()==3){
                res+= n-r;
                mpp[s[l]]--;
                if(mpp[s[l]]==0){
                    mpp.erase(s[l]);
                }
                l++;
            }
            r++;
        }
        return res;

    }
};