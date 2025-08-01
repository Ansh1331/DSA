class Solution {
public:
    vector<int> generateRows(int r){
        vector<int>res;
        res.push_back(1);
        long long ans=1;
        for(int i=1;i<r;i++){
            ans= ans*(r-i);
            ans= ans/i;
            res.push_back(ans);
        }
        return res;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=1;i<=numRows;i++){
            res.push_back(generateRows(i));
        }
        return res;
    }
};