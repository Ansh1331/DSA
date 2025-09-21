class Solution {
public:
    void helper(vector<vector<int>>& res,vector<int> temp,int index,int sum,int currentsum,int steps,int k){
        if(currentsum==sum && steps==k){
            res.push_back(temp);
            return;
        }

        for(int i=index;i<=9;i++){
            if(i>index && i==i-1) continue;
            if(currentsum + i >sum || steps>k) return;
            temp.push_back(i);
            helper(res,temp,i+1,sum,currentsum+i,steps+1,k);
            temp.pop_back();

        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        int currentsum=0;
        int steps=0;
        helper(res,temp,1,n,currentsum,steps,k);
        return res;
    }
};