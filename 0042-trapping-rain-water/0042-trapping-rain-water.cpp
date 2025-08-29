class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
        int l=0,r=n-1;
        int lmax=0,rmax=0;
        int res=0;


        while(l<=r){
            if(arr[l] < arr[r]){
                if(lmax>arr[l]){
                    res+= lmax-arr[l];
                }
                else{
                    lmax=arr[l];
                }
                l++;
            }
            else{
                if(rmax>arr[r]){
                    res+=rmax-arr[r];
                }
                else{
                    rmax=arr[r];
                }
                r--;
            }
        }   
        return res;
    }
};