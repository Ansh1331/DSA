class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        stack<int> st;
        int last=(2*n)-1;

        for(int i=last;i>=0;i--){
            while(!st.empty() && nums[i%n]>=st.top()){
                st.pop();
            }
            if(i<n){
                res[i]=st.empty() ? -1:st.top();
            }
            st.push(nums[i%n]);
        }
        return res;
    }
};