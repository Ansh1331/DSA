class Solution {
public:
    int expanda(string s,int start,int end){
        while(start>=0 && end<s.size() && s[start]==s[end]){
            start--;
            end++;
        }
        return end-start-1;
    }

    string longestPalindrome(string s) {
        int n=s.size();
        int start=0;
        int end=0;
        int maxlen=0;
        if(n==0) return "";
        for(int i=0;i<s.size();i++){
            int odd=expanda(s,i,i);
            int even=expanda(s,i,i+1);
            maxlen= max(odd,even);

            if(maxlen > end-start){
                start= i- ((maxlen-1)/2);
                end= i+ (maxlen/2);
            }
        }

        return s.substr(start,end-start+1);
        
    }
};