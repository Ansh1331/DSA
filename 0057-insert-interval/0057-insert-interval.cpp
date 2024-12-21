class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i=0;
        int n=arr.size();

        while(i<n && arr[i][1] < newInterval[0]){
            res.push_back(arr[i]);
            i++;
        }

        while(i<n && arr[i][0] <= newInterval[1]){
            newInterval[0]=min(arr[i][0], newInterval[0]);
            newInterval[1]=max(arr[i][1], newInterval[1]);
            i++;
        }
        res.push_back(newInterval);

        while(i<n){
            res.push_back(arr[i]);
            i++;
        }
        return res;
    }
};