class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum<=0){
                maxsum=max(sum,maxsum);
                sum=0;
            }
            else{
                maxsum=max(sum,maxsum);
            }
        }
        return maxsum;
    }
};