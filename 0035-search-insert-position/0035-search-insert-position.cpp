class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int n=arr.size();
        int low=0,high=n-1;
        int res=n;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]>=target){
                res=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return res;
    }
};