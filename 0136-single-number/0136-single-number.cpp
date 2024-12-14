class Solution {
public:
    int singleNumber(vector<int>& arr) {
        // int n=arr.size();
        // sort(arr.begin(),arr.end());
        // int res=-1;

        // for(int i=0;i<n-1;i+=2){
        //     if(arr[i] != arr[i+1]){
        //         return arr[i];
        //     }
        // }
        // return arr[n-1];
        int n=arr.size();
        int xorr=0;
        for(int i=0;i<n;i++){
            xorr= xorr ^ arr[i];
        }

        return xorr;
    }
};