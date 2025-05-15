class Solution {
public:
    int expand(string s, int start, int end){
        while(start>=0 && end<=s.size() && s[start]==s[end]){
            start--;
            end++;
        }
        return end-start-1;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==0) return "";
        if(n==1) return s;
        int maxlen=0;

        int start=0,end=0;
        for(int i=0;i<n;i++){
            int odd=expand(s,i,i);
            int even=expand(s,i,i+1);
            maxlen=max(odd,even);

            if(maxlen > end-start){
                start=i- (maxlen-1)/2;
                end= i+ (maxlen)/2;
            }
        }
        return s.substr(start,end-start+1);
    }
};