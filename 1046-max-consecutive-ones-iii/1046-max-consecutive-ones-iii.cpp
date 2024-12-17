class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int n=arr.size();
        int zcount=0;
        int left=0;
        int len=0;

        for(int right=0;right<n;right++){
            if(arr[right]==0){
                zcount++;
            }
            while(zcount>k){
                if(arr[left]==0){
                    zcount--;
                }
                left++;
            }
            len=max(len,right-left+1);
        }
        return len;
    }
};