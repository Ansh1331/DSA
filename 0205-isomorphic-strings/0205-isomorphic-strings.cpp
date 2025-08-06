class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n!=m) return false;
        vector<int> stringS(200,0);
        vector<int> stringT(200,0);

        for(int i=0;i<n;i++){
            if(stringS[s[i]] != stringT[t[i]]) return false;
            stringS[s[i]] =i+1;
            stringT[t[i]] =i+1;
        }
        return true;


    }
};

/*
f o o
b a r




*/