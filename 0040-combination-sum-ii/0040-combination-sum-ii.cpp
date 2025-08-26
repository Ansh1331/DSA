class Solution {
public:
    void helper(int index,int sum,vector<int>&arr,int target,vector<vector<int>>&res,vector<int>temp){
        if(sum==target){
            res.push_back(temp);
            return;
        }

        for(int i=index;i<arr.size();i++){
            if(i>index && arr[i]==arr[i-1]) continue;
            if(sum + arr[i] > target) return;

            temp.push_back(arr[i]);
            helper(i+1,sum+arr[i],arr,target,res,temp);
            temp.pop_back();   
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<vector<int>> res;
        sort(arr.begin(),arr.end());
        vector<int> temp;
        int sum=0;
        int index=0;
        helper(index,sum,arr,target,res,temp);
        return res;
    }
};