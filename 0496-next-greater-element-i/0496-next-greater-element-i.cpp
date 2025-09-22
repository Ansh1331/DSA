class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mpp;
        stack<int> st;
        int n=arr2.size();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr2[i]>=st.top()){
                st.pop();
            }

            mpp[arr2[i]]= st.empty()? -1:st.top();
            st.push(arr2[i]);
        }

        vector<int> res(arr1.size(),-1);
        for(int i=0;i<arr1.size();i++){
            res[i]=mpp[arr1[i]];
        }
        return res;
    }
};