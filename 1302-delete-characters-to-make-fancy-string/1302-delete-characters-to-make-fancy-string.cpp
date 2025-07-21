class Solution {
public:
    string makeFancyString(string s) {
        char curr;
        int count=0;
        string res="";
        for(char c:s){
            if(curr != c){
                curr=c;
                count=1;
                res+=c;
            }
            else{
                count++;
                if(count>2){
                    continue;
                }
                else{
                    res+=c;
                }
            }
        }
        return res;
    }
};