class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dis(n, vector<int>(m, 1e9));

        dis[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, {0, 0}});

        int delrow[] = {1, 0, -1, 0};
        int delcol[] = {0, -1, 0, 1};

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int dist = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if (row == n - 1 && col == m - 1) return dist;

            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int difference = abs(heights[nrow][ncol] - heights[row][col]);
                    int maxdiff = max(difference, dist);
                    if (maxdiff < dis[nrow][ncol]) {
                        dis[nrow][ncol] = maxdiff;
                        pq.push({maxdiff, {nrow, ncol}});
                    }
                }
            }
        }

        // ✅ Return the actual effort to reach (n-1, m-1)
        return dis[n-1][m-1];
    }
};
