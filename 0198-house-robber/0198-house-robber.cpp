class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
       // vector<int> dp(n+1,-1);
        int prev=nums[0];
        int prev2=0;
        
        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1){
                pick= nums[i] + prev2;
            }
            int notpick=0+ prev;
            int curr=max(pick,notpick);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};