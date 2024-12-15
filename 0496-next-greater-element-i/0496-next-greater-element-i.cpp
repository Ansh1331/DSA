#include<stack>
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        vector<int> res(n,-1);
        vector<int> final(nums1.size());
        stack<int> st;

        for(int i=n-1;i>=0;i--){
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            if (!st.empty()) {
                res[i] = st.top();
            }
            st.push(nums2[i]);
        }

        for(int k=0;k<nums1.size();k++){
            int index=-1;
            for(int l=0;l<nums2.size();l++){
                if(nums1[k]==nums2[l]){
                    index=l;
                    break;
                }
            }
            if(index!=-1){
                final[k]=res[index];
            }
        }
        return final;
    }
};