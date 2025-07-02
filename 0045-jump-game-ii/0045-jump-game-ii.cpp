class Solution {
public:
    int jump(vector<int>& arr) {
        int jumps=0;
        int l=0,r=0;

        while(r<arr.size()-1){
            int maxJump=l;

            for(int i=l;i<=r;i++){
                maxJump= max(maxJump, i+arr[i]);
            }
            l=r+1;
            r=maxJump;
            jumps++;
        }
        return jumps;
    }
};