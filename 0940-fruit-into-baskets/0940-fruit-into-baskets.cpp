class Solution {
public:
    int totalFruit(vector<int>& arr) {
        map<int,int> mpp; //type,freq
        int l=0;
        int r=0;
        int n=arr.size();
        int count=0;

        while(r<n){
            mpp[arr[r]]++;
            
            while(mpp.size()>2){
                mpp[arr[l]]--;
                if(mpp[arr[l]]==0){
                    mpp.erase(arr[l]);
                }
                l++;
            }

            int len=r-l+1;
            count=max(count,len);
            r++;
        }
        return count;
    }
};