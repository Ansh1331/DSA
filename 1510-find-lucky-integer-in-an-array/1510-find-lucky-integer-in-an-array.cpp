class Solution {
public:
    int findLucky(vector<int>& arr) {
        int res=-1;
        map<int,int> mpp;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }

        for(auto it:mpp){
            if(it.first == it.second){
                if(it.second > res){
                    res=it.second;
                }
            }
        }
        return res;
    }
};
