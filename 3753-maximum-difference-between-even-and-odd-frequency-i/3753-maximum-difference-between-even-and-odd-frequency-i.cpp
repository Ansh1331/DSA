class Solution {
public:
    int maxDifference(string s) {
        map<char,int> mpp;
        for(char c:s){
            mpp[c]++;
        }
        int odd=-1e8;
        int even=1e8;
        for(auto it:mpp){
            if(it.second %2 ==0){
                even=min(even,it.second);
            }
            else{
                odd=max(odd,it.second);
            }
        }
        return odd-even;
    }
};