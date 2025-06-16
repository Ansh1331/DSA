class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int smallest=nums[0];
        int result=-1;
        for(int i=1;i<n;i++){
            if(nums[i] > smallest){
                result= max(result,nums[i]-smallest);
            }
            smallest=min(smallest,nums[i]);
        }
        return result;
    }
};