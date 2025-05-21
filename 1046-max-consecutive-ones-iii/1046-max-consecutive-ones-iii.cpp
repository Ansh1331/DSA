class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int l=0,r=0;
        int n=arr.size();
        int res=0;
        int zcount=0;

        while(r<n){
            if(arr[r]==0){
                zcount++;
            }
            while(zcount>k){
                if(arr[l]==0){
                    zcount--;
                }
                l++;
            }
        
            int len=r-l+1;
            res=max(res,len);
            r++;
        }
    return res;
    }
};