class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n=arr.size(); 
        vector<int> res; //n-k=5
        list<int> lt;
        int j=0;
        
        for(int i=0;i<n;i++){
            if(!lt.empty() && lt.front()<=i-k){
                lt.pop_front();
            }
            while(!lt.empty() && arr[lt.back()]<=arr[i]){
                lt.pop_back();
            }
            lt.push_back(i);
            if(i>=k-1){
                res.push_back(arr[lt.front()]);
            }
        }
        return res;
    }
};