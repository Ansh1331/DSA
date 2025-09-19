class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n!=m) return false;
        vector<int> mpp1(200,0);
        vector<int> mpp2(200,0);

        for(int i=0;i<n;i++){
            if(mpp1[s[i]]!= mpp2[t[i]]) return false;
            mpp1[s[i]]++;
            mpp2[t[i]]++;
        }

        return true;
    }
};