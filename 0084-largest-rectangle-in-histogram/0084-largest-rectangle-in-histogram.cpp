class Solution {
public:
    vector<int> nextsmallestindex(vector<int>arr,int n){
        vector<int> res(n,0);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            res[i]=st.empty() ? n:st.top();
            st.push(i);
        }
        return res;
    }

    vector<int> previoussmallelt(vector<int> arr,int n){
        vector<int> res(n,0);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                st.pop();
            }
            res[i]=st.empty()? -1:st.top();
            st.push(i);
        }
        return res;
    }
    
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        int maxi=0;
        vector<int> nse(n);
        vector<int> pse(n);
        nse= nextsmallestindex(arr,n);
        pse= previoussmallelt(arr,n);

        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]*(nse[i]-pse[i]-1));
        }
        return maxi;
    }
};