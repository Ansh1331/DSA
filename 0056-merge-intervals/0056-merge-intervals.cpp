class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> res;
        res.push_back(arr[0]);

        for(int i=1;i<n;i++){
            auto it=res.back();
            int end=it[1];
            int currStart=arr[i][0];
            int currEnd=arr[i][1];
            if(currStart<=end){
                res.back()[1]=max(end,currEnd);
            }
            else{
                res.push_back(arr[i]);
            }
        }
        return res;

    }
};