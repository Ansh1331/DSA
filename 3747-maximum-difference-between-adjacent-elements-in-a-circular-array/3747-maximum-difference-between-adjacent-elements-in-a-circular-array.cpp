class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n=nums.size();
        int res=INT_MIN;
        for(int i=0;i<=n;i++){
            res = max(abs(nums[(i+1)%n] - nums[i%n]) , res);
        }
        return res;
    }
};