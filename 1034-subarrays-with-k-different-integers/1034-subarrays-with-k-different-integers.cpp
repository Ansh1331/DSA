class Solution {
public:
    int atmostsubarray(vector<int>arr,int k){
        int n=arr.size();
        int l=0;
        int r=0;
        map<int,int> mpp;
        int res=0;

        while(r<n){
            mpp[arr[r]]++;
            while(mpp.size()>k){
                mpp[arr[l]]--;
                if(mpp[arr[l]]==0){
                    mpp.erase(arr[l]);
                }
                l++;
            }
            int len=r-l+1;
            res+=len;
            r++;
        }
        return res;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostsubarray(nums,k) - atmostsubarray(nums,k-1);
    }
};