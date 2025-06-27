class Solution {
public:
    void helper(vector<int>& arr,vector<vector<int>>& ans,vector<int> temp,int target,int sum,int index){
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        if(index>=arr.size() || sum>target){
            return;
        }

        //include
        int el=arr[index];
        temp.push_back(el);
        helper(arr,ans,temp,target,sum+el,index);

        //exclude
        temp.pop_back();
        helper(arr,ans,temp,target,sum,index+1);

    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(arr,ans,temp,target,0,0);
        return ans;
    }
};