#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);  // Initialize all nodes as uncolored (-1)

        for (int i = 0; i < n; i++) {  // Iterate over all components
            if (color[i] == -1) {  // If node is uncolored, start BFS
                queue<int> q;
                q.push(i);
                color[i] = 0;  // Start coloring with 0

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (auto it : graph[node]) {
                        if (color[it] != -1 && color[it] == color[node]) {
                            return false;  // Conflict found
                        }
                        else if (color[it] == -1) {  
                            color[it] = !color[node];  // Assign opposite color
                            q.push(it);
                        }
                    }
                }
            }
        }
        return true;
    }
};
