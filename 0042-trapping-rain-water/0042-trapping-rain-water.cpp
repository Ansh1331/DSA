class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
        int lmax,rmax,total=0;
        int l=0;
        int r=n-1;

        while(l<r){
            if(arr[l] < arr[r]){
                if(lmax>arr[l]){
                    total+= lmax-arr[l];
                }
                else{
                    lmax=arr[l];
                }
                l++;
            }
            else{
                if(rmax> arr[r]){
                    total+= rmax-arr[r];
                }
                else{
                    rmax=arr[r];
                }
                r--;
            }
        }
        return total;
    }
};