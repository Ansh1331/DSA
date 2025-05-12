class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0,prefixsum=0;
        int n=nums.size();
        map<int,int> mpp;
        mpp[0]=1;

        for(int i=0;i<n;i++){
            prefixsum+=nums[i];
            int rem=prefixsum-k;
            count+=mpp[rem];
            mpp[prefixsum]++;
        }
        return count;
    }
};