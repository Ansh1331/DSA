class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int index=0;
        for(int i=1;i<n;i++){
            if(nums[i] != nums[index]){
                nums[index+1] = nums[i];
                index++;
            }
        }
        return index+1;
    }
};