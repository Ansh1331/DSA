class Solution {
public:
    int findLargestReact(vector<int>& height) {
        stack<int> st;
        int maxArea = 0;

        height.push_back(0); // Sentinel to flush out stack
        int n = height.size();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[st.top()] > height[i]) {
                int h = height[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                int area = h * width;
                maxArea = max(maxArea, area);
            }
            st.push(i);
        }

        height.pop_back(); // Clean up (optional)
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int n = matrix.size(), m = matrix[0].size();
        vector<int> height(m, 0);
        int maxRect = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                height[j] = (matrix[i][j] == '1') ? height[j] + 1 : 0;
            }
            maxRect = max(maxRect, findLargestReact(height));
        }

        return maxRect;
    }
};
