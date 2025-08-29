class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>> res;
        res.push_back({arr[0][0],arr[0][1]});
        for(int i=1;i<arr.size();i++){
            int currStart=arr[i][0];
            int currEnd=arr[i][1];
            int back= res.back()[1];
            if(back>= currStart){
                res.back()[1]= max(res.back()[1] , currEnd);
            }
            else{
                res.push_back({currStart,currEnd});
            }
        }
        return res;
    }
};