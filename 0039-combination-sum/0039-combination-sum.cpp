class Solution {
public:
    void helper(int index,int sum,vector<int>&arr,int target,vector<vector<int>>&res,vector<int>temp){
        if(sum==target){
            res.push_back(temp);
            return;
        }

        if(sum>target || index>=arr.size()){
            return;
        }

        helper(index+1,sum,arr,target,res,temp);

        int el=arr[index];
        temp.push_back(el);
        helper(index,sum+el,arr,target,res,temp);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        int sum=0;
        int index=0;
        helper(index,sum,arr,target,res,temp);
        return res;
    }
};