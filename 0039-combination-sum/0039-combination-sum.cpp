class Solution {
public:

    void solve(vector<int> candidates,int target,vector<vector<int>> & res,vector<int> &currentcombination,int index,int currentsum){
        if(currentsum==target){
            res.push_back(currentcombination);
            return;
        }

        if(currentsum>target || index>=candidates.size()){
            return;
        }
        
        //include
        currentcombination.push_back(candidates[index]);
        solve(candidates,target,res,currentcombination,index,currentsum+candidates[index]);

        //exclude
        currentcombination.pop_back();
        solve(candidates,target,res,currentcombination,index+1,currentsum);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> currentcombination;
        int index=0;
        int currentsum=0;
        solve(candidates,target, res,currentcombination,index,currentsum);
        return res;
    }
};