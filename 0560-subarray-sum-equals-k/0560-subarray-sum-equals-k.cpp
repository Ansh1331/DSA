class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        unordered_map<int,int> mpp;
        mpp[0]=1;
        int count=0;
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            int rem=abs(k-sum);
            if(mpp.find(rem)!=mpp.end()){
                count++;
            }
            mpp[sum]++;
        }
        return count;
    }
};