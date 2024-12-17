class Solution {
public:
    int atmostsubarrays(vector<int>& nums, int k){
        if(k<0){
            return 0;
        }
        int l=0;
        int r=0;
        int res=0;
        int oddcount=0;
        while(r<nums.size()){
            if((nums[r]%2)==1){
                oddcount++;
            }
            while(oddcount>k){
                if((nums[l]%2)==1){
                    oddcount--;
                }
                l++;
            }
            res+=(r-l+1);
            r++;
        }
        return res;
    }


    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmostsubarrays(nums,k)- atmostsubarrays(nums,k-1);
    }
};