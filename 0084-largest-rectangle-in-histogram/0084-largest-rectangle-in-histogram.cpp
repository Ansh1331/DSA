class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        stack<int> st;
        int maxarea=0;
        int nse=-1;
        int pse=-1;

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                int el=arr[st.top()];
                st.pop();
                nse=i;
                pse=st.empty() ? -1:st.top();

                maxarea=max(maxarea, el*(nse-pse-1));
            }
            st.push(i);
        }

        while(!st.empty()){
            int el=arr[st.top()];
            st.pop();
            nse=n;
            pse=st.empty() ? -1:st.top();
            maxarea=max(maxarea, el*(nse-pse-1));
        }

        return maxarea;
    }
};