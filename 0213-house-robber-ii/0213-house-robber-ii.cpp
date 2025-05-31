class Solution {
public:
    // Code for space optimization last lecture
    long long int rob2(vector<int>& nums) {
        int n=nums.size();
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

    long long int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp1,temp2;
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }

        long long int res=max (rob2(temp1),rob2(temp2));
        return res;
        
    }
};