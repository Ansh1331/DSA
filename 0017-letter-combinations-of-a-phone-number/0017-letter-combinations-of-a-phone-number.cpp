class Solution {
public:
    void helper(string digits,vector<string>&res,string temp,vector<string>&digToChar,int index){
        if(index== digits.size()){
            res.push_back(temp);
            return;
        }

        int digit=digits[index]-'0';
        string letters=digToChar[digit];

        for(char letter:letters){
            temp.push_back(letter);
            helper(digits,res,temp,digToChar,index+1);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string temp="";
        if(digits.empty()) return {};

        vector<string> digToChar={"", "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        helper(digits,res,temp,digToChar,0);
        return res;

    }
};