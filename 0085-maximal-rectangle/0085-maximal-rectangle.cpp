class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0; // Handle empty matrix edge case
        int m = matrix[0].size();
        int newmatrix[n][m];
        int maxarea=0; 
        stack<int> st;
        int nse=-1;
        int pse=-1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0') {
                    newmatrix[i][j] = 0; // Reset height if '0'
                } else {
                    newmatrix[i][j] = (i == 0 ? 1 : newmatrix[i-1][j] + 1); // Increment height for '1'
                }
            }
        }

        for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            while (!st.empty() && newmatrix[i][st.top()] > newmatrix[i][j]) {
                int el = newmatrix[i][st.top()];
                st.pop();
                int nse = j;
                int pse = st.empty() ? -1 : st.top();
                maxarea = max(maxarea, el * (nse - pse - 1));
            }
            st.push(j);
        }
        while (!st.empty()) {
            int el = newmatrix[i][st.top()];
            st.pop();
            int nse = m;
            int pse = st.empty() ? -1 : st.top();
            maxarea = max(maxarea, el * (nse - pse - 1));
        }
        }

        return maxarea;
    }
};