class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> st;
        int res=INT_MIN;
        int nse=-1,pse=-1;
        int n=arr.size();

        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[i] < arr[st.top()]){
                int index=st.top();
                st.pop();
                int el=arr[index];
                nse=i;
                pse=st.empty() ? -1:st.top();

                res=max(res, el*(nse-pse-1));
            }
            st.push(i);
        }

        while(!st.empty()){
            int index=st.top();
                st.pop();
                int el=arr[index];
                nse=n;
                pse=st.empty() ? -1:st.top();

                res=max(res, el*(nse-pse-1));
        }
        return res;
    }
};