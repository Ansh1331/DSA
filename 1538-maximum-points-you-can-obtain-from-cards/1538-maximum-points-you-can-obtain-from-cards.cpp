class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n=arr.size();
        int lsum=0;
        int rsum=0;
        int l=k-1;
        int r=n-1;

        for(int i=0;i<k;i++){
            lsum+=arr[i];
        }
        int res=lsum;

        while(l>=0){
            lsum-=arr[l];
            rsum+=arr[r];
            l--;
            r--;
            res=max(res,lsum+rsum);
        }
        return res;
    }
};