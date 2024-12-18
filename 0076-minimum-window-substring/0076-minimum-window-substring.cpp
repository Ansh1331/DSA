class Solution {
public:
    string minWindow(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        int l=0; int r=0;
        int minlen=INT_MAX;
        unordered_map<char,int> mpp;
        int count=0;
        int curr=0;
        int startindex=-1;

        for(int i=0;i<n2;i++){
            mpp[t[i]]++;
            count++;
        }

        while(r<n1){
            if(mpp[s[r]] > 0){
                curr++;
            }
            mpp[s[r]]--;

            while(curr==count){
                if(r-l+1 < minlen){
                    minlen = r-l+1;
                    startindex=l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0) curr--;
                l++;
            }
            r++;
        }
        return startindex==-1 ? "":s.substr(startindex,minlen);
    }
};