class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            if(i>0 && arr[i]==arr[i-1]) continue;
            int j=i+1;
            int k=n-1;
            while(j<k){
                // if(j!=i+1 && arr[j]==arr[j-1]) continue;
                sum = arr[i] +arr[j] +arr[k];
                if(sum==0){
                    res.push_back({arr[i],arr[j],arr[k]});
                    j++;
                    k--;
                    while(j<k && arr[j]==arr[j-1]) j++;
                    while(j<k && arr[k]==arr[k+1]) k--;
                }
                else if(sum<0){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return res;
    }
};