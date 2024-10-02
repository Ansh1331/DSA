class Solution {
public:

    void solve(int k,int target,vector<vector<int>> & res,vector<int> &currentcombination,int index,int currentsum){
        if(currentsum==target && currentcombination.size()==k){
            res.push_back(currentcombination);
            return;
        }

        if(currentsum>target || currentcombination.size()>k){
            return;
        }
         
        for(int i=index;i<10;i++){  
            //if(i> index) continue;
            //if(currentsum+i>target) return;

            currentcombination.push_back(i);
            solve(k,target,res,currentcombination,i+1,currentsum+i);
            currentcombination.pop_back(); 
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> currentcombination;
        int index=1;
        int currentsum=0;
        solve(k, n,res,currentcombination,index,currentsum);
        return res;
    }
};