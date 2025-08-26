class Solution {
public:
    void helper(vector<int>&arr, vector<vector<int>>&res,vector<int>temp,int index,int n,int sum,int target){
        if(index==n){
            if(sum==target){
                res.push_back(temp);
                return;
            }
            return;
        }

        //exclude
        helper(arr,res,temp,index+1,n,sum,target);

        if(sum+arr[index] <= target){
            temp.push_back(arr[index]);
            helper(arr,res,temp,index,n,sum+arr[index],target);
        }
        
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        int n=arr.size();
        int sum=0;

        helper(arr,res,temp,0,n,sum,target);
        return res;
    }
};