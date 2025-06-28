class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
         vector<pair<int, int>> mpp;
        for(int i=0;i<nums.size();i++){
            mpp.push_back({i,nums[i]});
        }

        sort(mpp.begin(),mpp.end(),[](auto &a, auto &b){
            return a.second> b.second;
        });
        vector<pair<int, int>> sortedMap(mpp.begin(),mpp.begin()+k);

        sort(sortedMap.begin(),sortedMap.end(),[](auto &a, auto &b){
            return a.first< b.first;
        });
        vector<int> res;
        for(auto it:sortedMap){
            res.push_back(it.second);
        }
        return res;
        

    }
};
