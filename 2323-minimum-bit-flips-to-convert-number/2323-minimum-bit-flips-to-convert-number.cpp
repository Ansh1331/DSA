class Solution {
public:
    int setbits(int num){
        int res=0;
        for(int i=0;i<=31;i++){
            if(num & (1<<i)){
                res++;
            }
        }
        return res;
    }


    int minBitFlips(int start, int goal) {
        int num= start ^ goal;

        int count= setbits(num);
        return count; 
    }
};
