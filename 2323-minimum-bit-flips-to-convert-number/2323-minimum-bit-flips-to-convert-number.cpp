class Solution {
public:
    int countbits(int num){
        int count=0;
        for(int i=0;i<=31;i++){
            if(num & (1<<i) ){
                count++;
            }
        }
        return count;
    }
    int minBitFlips(int start, int goal) {
        int num=start^goal;
        int res=countbits(num);
        return res;
    }
};