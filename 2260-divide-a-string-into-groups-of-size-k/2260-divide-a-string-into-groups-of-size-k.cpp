class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n=s.size();

        for(int i=0;i<n;i+=k){
            string str="";
            for(int j=0;j<k;j++){
                if(i+j >=n ){
                    str+= fill;
                }
                else{
                    str += s[i+j];
                }
            }
            ans.push_back(str);
        }
        return ans;
    }
};