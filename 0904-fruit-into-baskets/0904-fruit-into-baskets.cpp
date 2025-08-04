class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int res=0;
        int l=0,r=0;
        int n=arr.size();
        map<int,int>mpp;

        while(r<n){
            if(mpp.find(arr[r]) != mpp.end()){
                mpp[arr[r]]++;
                r++;
            }
            else{
                while(mpp.size()>=2){
                    mpp[arr[l]]--;
                    if(mpp[arr[l]] == 0) mpp.erase(arr[l]);
                    l++;
                }
                mpp[arr[r]]++;
                r++;
            }
            res=max(res,r-l);
        }
        return res;
    }
};