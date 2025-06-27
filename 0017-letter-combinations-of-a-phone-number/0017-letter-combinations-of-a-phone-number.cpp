class Solution {
public:
    void helper(string &digits,vector<string> & ans,string temp,vector<string> &digitToChar,int index){
        if(index== digits.size()){
            ans.push_back(temp);
            return;
        }

        int digit= digits[index]-'0';
        string letters= digitToChar[digit];

        for(char letter:letters){
            temp.push_back(letter);
            helper(digits,ans,temp,digitToChar,index+1);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        vector<string> ans;
        string temp;
        vector<string> digitToChar={
            "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };
        helper(digits,ans,temp,digitToChar,0);
        return ans;
    }
};