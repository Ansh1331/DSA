class Solution {
public:
    char kthCharacter(int k) {
        int count= ceil(k/2.0);

        string begin= "a";

        while(begin.size()<k){
            string toAppend="";
            for(int j=0;j<begin.size();j++){
                char nextChar= (begin[j]== 'z') ? 'a': begin[j]+1;
                toAppend+= nextChar;
            }
            begin += toAppend;
        }
        return begin[k-1];
    }
};