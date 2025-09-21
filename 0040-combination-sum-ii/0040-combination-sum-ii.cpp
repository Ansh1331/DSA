class Solution {
public:
    void helper(vector<int>& arr,vector<vector<int>>& res,vector<int> temp,int index,int n,int sum,int currentsum){
        if(currentsum==sum){
            res.push_back(temp);
            return;
        }

        for(int i=index;i<n;i++){
            if(i>index && arr[i]==arr[i-1]) continue;
            if(currentsum + arr[i] >sum) return;
            temp.push_back(arr[i]);
            helper(arr,res,temp,i+1,n,sum,currentsum+arr[i]);
            temp.pop_back();

        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> res;
        vector<int> temp;
        int currentsum=0;
        helper(arr,res,temp,0,n,target,currentsum);
        return res;
    }
};