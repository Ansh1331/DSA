class Solution {
public:
    void helper(int index,vector<int>& arr,vector<vector<int>>& res,vector<int>temp,int n){
        if(index==n){
            res.push_back(temp);
            return;
        }

        //exclude
        helper(index+1,arr,res,temp,n);

        //include
        temp.push_back(arr[index]);
        helper(index+1,arr,res,temp,n);
    }


    vector<vector<int>> subsets(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> res;
        vector<int> temp;
        helper(0,arr,res,temp,n);
        return res;
    }
};