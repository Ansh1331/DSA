class Solution {
public:
    int jump(vector<int>& arr) {
        int n=arr.size();
        int l=0;
        int r=0;
        int jumps=0;
        
        while(r<n-1){
            int farthest=0;
            for(int i=l;i<=r;i++){
                farthest=max(farthest,i+arr[i]);
            }
            l=r+1;
            r=farthest;
            jumps++;
        }
        return jumps;
    }
};