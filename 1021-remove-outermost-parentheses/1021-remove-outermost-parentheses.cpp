class Solution {
public:
    string removeOuterParentheses(string s) {
        string res="";
        int balance=0;

        for(char c:s){
            if(c=='('){
                if(balance > 0){
                    res+= c;
                }
                balance++;
            }
            else{
                balance--;
                if(balance>0){
                    res+=c;
                }
            }
        }
        return res;
    }
};