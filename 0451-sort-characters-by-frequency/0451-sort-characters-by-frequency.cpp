class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        map<char,int> mpp;
        for(char c:s){
            mpp[c]++;
        }

        string res="";
        while(!mpp.empty()){
            char c='\0';
            int count=0;
            for(auto it:mpp){
                if(it.second > count){
                    count=it.second;
                    c=it.first;
                }
            }
            res.append(count,c);
            mpp.erase(c);
        }
        return res;


    }
};