class Solution {
public:
    string reverse(string str){
        int start=0;
        int end=str.size()-1;
        while(start<end){
            char temp=str[start];
            str[start]=str[end];
            str[end]=temp;
            start++;
            end--;
        }
        return str;
    }

    string removeKdigits(string num, int k) {
        stack<char> st;
        int n=num.size();
        string res="";

        for(int i=0;i<n;i++){
            if(k==n){
                return "0";
            }
            while(!st.empty() && st.top()>num[i] && k!=0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k!=0){
            st.pop();
            k--;
        }
        while(!st.empty()){
            res+= string(1,st.top());
            st.pop();
        }

        while(res.size()!=0 && res.back()=='0'){
            res.pop_back();
        }
        string finall=reverse(res);
        if(finall.size()==0) return "0";
        return finall;
    }
};