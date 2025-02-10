#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int freshCount = 0;  // ✅ Count fresh oranges
        int mins = 0;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        // ✅ Push all initially rotten oranges to queue & count fresh oranges
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == 2) {
                    q.push({row, col});
                } else if (grid[row][col] == 1) {
                    freshCount++;
                }
            }
        }

        // ✅ Multi-source BFS from all rotten oranges
        while (!q.empty() && freshCount > 0) {
            int size = q.size();
            mins++;  // ✅ Increase time for each BFS level

            for (int i = 0; i < size; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for (int j = 0; j < 4; j++) {
                    int nrow = row + delrow[j];
                    int ncol = col + delcol[j];

                    if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == 1) {
                        grid[nrow][ncol] = 2;  // Rot the orange
                        q.push({nrow, ncol});
                        freshCount--;  // ✅ Decrease fresh orange count
                    }
                }
            }
        }

        // ✅ If fresh oranges are left, return -1
        return (freshCount == 0) ? mins : -1;
    }
};
