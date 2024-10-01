class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s1=0;
        int s2=0;
        int n=nums.size();

        s1= (n*(n+1))/2;
        for(int i=0;i<n;i++){
            s2+=nums[i];
        }
        return (s1-s2);
    }
};