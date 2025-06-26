class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mpp;
            mpp['I']=1;
            mpp['V']=5;
            mpp['X']=10;
            mpp['L']=50;
            mpp['C']=100;
            mpp['D']=500;
            mpp['M']=1000;

        int sum=0;
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            sum+= mpp[s[i]];
            if(i-1>=0 && mpp[s[i-1]] < mpp[s[i]]){
                sum -= mpp[s[i-1]];
                i--;
            }
        }
        return sum;
    }
};