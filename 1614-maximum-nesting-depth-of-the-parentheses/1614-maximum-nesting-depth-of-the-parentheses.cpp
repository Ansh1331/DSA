class Solution {
public:
    int maxDepth(string s) {
        int balance=0;
        int count=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                count++;
                balance=max(balance,count);
            }
            else if(s[i]==')'){
                count--;
            }
            else{
                continue;
            }
        }
        return balance;
    }
};