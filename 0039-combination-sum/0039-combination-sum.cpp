class Solution {
public:
    void helper(vector<int>& arr,vector<vector<int>>& res,vector<int> temp,int index,int n,int sum,int currentsum){
        if(currentsum==sum){
            res.push_back(temp);
            return;
        }

        if(currentsum>sum || index>=n){
            return;
        }

        helper(arr,res,temp,index+1,n,sum,currentsum);

        temp.push_back(arr[index]);
        helper(arr,res,temp,index,n,sum,currentsum+arr[index]);
        temp.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<vector<int>> res;
        vector<int> temp;
        int currentsum=0;
        helper(arr,res,temp,0,n,target,currentsum);
        return res;
    }
};