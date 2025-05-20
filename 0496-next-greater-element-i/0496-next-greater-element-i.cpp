class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        stack<int> st;
        vector<int> res(n);
        unordered_map<int,int> greater;

        for(int i=m-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }

            greater[nums2[i]] = st.empty() ? -1:st.top();
            st.push(nums2[i]);
        }
        for(int i=0;i<n;i++){
            res[i]=greater[nums1[i]];
        }
        return res;
    }
};