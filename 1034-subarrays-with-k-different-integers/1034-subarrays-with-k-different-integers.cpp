class Solution {
public:
    int atmostsubarrays(vector<int>& arr,int k){
        if(k<0){
            return 0;
        }
        int n=arr.size();
        int l=0;
        int r=0;
        int res=0;
        unordered_map<int,int> mpp;

        while(r<n){
            mpp[arr[r]]++;

            while(mpp.size()>k){
                mpp[arr[l]]--;
                if(mpp[arr[l]]==0){
                    mpp.erase(arr[l]);
                }
                l++;
            }
            res+= r-l+1;
            r++;
        }
        return res;
    }


    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostsubarrays(nums,k) - atmostsubarrays(nums,k-1); 
    }
};