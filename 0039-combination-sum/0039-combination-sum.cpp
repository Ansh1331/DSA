class Solution {
public:
    void helper(int index,int currentsum,vector<int> candidates,int target,vector<vector<int>> & res,vector<int>temp){
        if(currentsum==target){
            res.push_back(temp);
            return;
        }
        if(index>=candidates.size() || currentsum>target){
            return;
        }
        //include
        temp.push_back(candidates[index]);
        helper(index,currentsum+candidates[index],candidates,target,res,temp);

        //exclude
        temp.pop_back();
        helper(index+1,currentsum,candidates,target,res,temp);
        

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        int index=0;
        int currentsum=0;
        helper(index,currentsum,candidates,target,res,temp);
        return res;
    }
};