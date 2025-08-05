class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        unordered_map<int,int> mpp;
        mpp[0]=1;

        int sum=0;
        int count=0;
        for(int i=0;i<arr.size();i++){
            sum+= arr[i];
            int rem= sum-k;
            if(mpp.find(rem) != mpp.end()){
                count+= mpp[rem];
            }
            mpp[sum]++;
        }   
        return count;
    }
};


// 1 2 3
/*

0 - 0
1 - 1




*/