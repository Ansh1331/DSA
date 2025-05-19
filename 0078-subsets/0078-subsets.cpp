class Solution {
public:
    void helper(int count,int n,vector<int> temp,vector<vector<int>>& res,vector<int>nums){
        if(count>=n){
            res.push_back(temp);
            return;
        }

        //exclude
        helper(count+1,n,temp,res,nums);

        //include
        int el=nums[count];
        temp.push_back(el);
        helper(count+1,n,temp,res,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        int n=nums.size();
        helper(0,n,temp,res,nums);
        return res;
    }
};