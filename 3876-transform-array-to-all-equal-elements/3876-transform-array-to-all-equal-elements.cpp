class Solution {
public:
    bool helper(vector<int> nums,int n,int k, int target){
        
        for(int i=0;i<n-1;i++){
            if(nums[i] != target){
                nums[i] *= -1;
                nums[i+1] *= -1;
                k--;
                if(k<0) return false;
            }
        }
        return nums[n-1]==target;

    }

    bool canMakeEqual(vector<int>& nums, int k) {
        int n=nums.size();
        bool res1=helper(nums,n,k,1);
        bool res2=helper(nums,n,k,-1);
        return res1 | res2;
    }
};