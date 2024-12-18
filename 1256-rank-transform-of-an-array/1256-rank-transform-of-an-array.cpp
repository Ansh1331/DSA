class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        if(n==0){
            return{};
        }

        set<int> uniqueElements(arr.begin(),arr.end());

        unordered_map<int,int> mpp;
        int rank=1;

        for(const int &ele :uniqueElements){
            mpp[ele]=rank++;
        }

        vector<int> ans;

        for(int i=0;i<arr.size();i++){
            ans.push_back(mpp[arr[i]]);
        }
        return ans;
    }
};