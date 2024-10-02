class Solution {
public:
    void solve(vector<int>arr,int index,vector<vector<int>> & res,vector<int> &currentcombination){
        res.push_back(currentcombination);

        for(int i=index;i<arr.size();i++){
            if(i> index && arr[i]==arr[i-1]) continue;
            currentcombination.push_back(arr[i]);
            solve(arr,i+1,res,currentcombination);
            currentcombination.pop_back(); 
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        int index=0;
        vector<vector<int>> res;
        vector<int> currentcombination;
        sort(arr.begin(),arr.end());
        solve(arr,index,res,currentcombination);
        return res;
    }
};