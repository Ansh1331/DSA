class Solution {
public:
    void helper(vector<int>& arr,vector<vector<int>>& res,vector<int>& temp,int index,int n){
        if(index>=n){
            res.push_back(temp);
            return;
        }

        //exclude
        helper(arr,res,temp,index+1,n);
        
        //include
        temp.push_back(arr[index]);
        helper(arr,res,temp,index+1,n);
        temp.pop_back();

    }

    vector<vector<int>> subsets(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> res;
        vector<int> temp;
        helper(arr,res,temp,0,n);
        return res;
    }
};