class Solution {
public:

    void solve(vector<int> nums,vector<int> output,int index,vector<vector<int>> & res ){
        if(index>=nums.size()){
            res.push_back(output);
            return;
        }

        //exclude
        solve(nums,output,index+1,res);

        //include
        int element=nums[index];
        output.push_back(element);
        solve(nums,output,index+1,res);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> output;
        int index=0;
        solve(nums,output,index,res);
        return res;
    }
};