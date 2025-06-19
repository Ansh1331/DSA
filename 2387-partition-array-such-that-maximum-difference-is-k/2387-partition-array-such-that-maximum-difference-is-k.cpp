class Solution {
public:
    int partitionArray(vector<int>& arr, int k) {
        int n=arr.size();
        int count=1;
        sort(arr.begin(),arr.end());
        int mini=arr[0],maxi=arr[0];
        for(int i=1;i<n;i++){
            mini=min(mini,arr[i]);
            maxi=max(maxi,arr[i]);
            if(abs(maxi-mini) > k){
                count++;
                mini=maxi=arr[i];
            }
        }
        return count;

    }
};