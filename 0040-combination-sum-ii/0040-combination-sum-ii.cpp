class Solution {
public:

    void solve(vector<int> candidates,int target,vector<vector<int>> & res,vector<int> &currentcombination,int index,int currentsum){
        if(currentsum==target){
            res.push_back(currentcombination);
            return;
        }
         
        for(int i=index;i<candidates.size();i++){
            if(i> index && candidates[i]==candidates[i-1]) continue;
            if(currentsum+candidates[i]>target) return;

            currentcombination.push_back(candidates[i]);
            solve(candidates,target,res,currentcombination,i+1,currentsum+candidates[i]);
            currentcombination.pop_back(); 
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> currentcombination;
        int index=0;
        int currentsum=0;
        sort(candidates.begin(),candidates.end());
        solve(candidates,target, res,currentcombination,index,currentsum);
        return res;
    }
};