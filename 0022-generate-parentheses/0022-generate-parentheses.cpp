class Solution {
public:
    void helper(string str,int open,int close,int n,vector<string>& res){
        if(open==n && close==n){
            res.push_back(str);
            return;
        }
        if(open<n){
            helper(str+'(',open+1,close,n,res);
        }
        if(open>close){
            helper(str+')',open,close+1,n,res);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper("",0,0,n,res);
        return res;
    }
};