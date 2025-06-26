class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mpp;
        int n=s.size();
        mpp['I']=1;
        mpp['V']=5;
        mpp['X']=10;
        mpp['L']=50;
        mpp['C']=100;
        mpp['D']=500;
        mpp['M']=1000;

        int res=0;
        for(int i=0;i<n;i++){
            if(mpp[s[i+1]] > mpp[s[i]]){
                res-= mpp[s[i]];
            }
            else{
                res+=mpp[s[i]];
            }
        }
        return res;
    }
};