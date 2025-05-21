class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> res;
        list<int> lt;

        for(int i=0;i<n;i++){
            if(!lt.empty() && lt.front()<=i-k){
                lt.pop_front();
            }
            while(!lt.empty()&& nums[lt.back()] <= nums[i]){
                lt.pop_back();
            }
            lt.push_back(i);
            if(i>=k-1){
                res.push_back(nums[lt.front()]);
            }
        }
        return res;
    }
};