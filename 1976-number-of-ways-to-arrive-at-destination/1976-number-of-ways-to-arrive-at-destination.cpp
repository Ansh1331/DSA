class Solution {
public:
    const int mod = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long> dis(n, 1e18);  // use long long to avoid overflow
        vector<int> ways(n, 0);
        vector<vector<pair<int, int>>> adj(n);

        for (auto& it : roads) {
            int u = it[0], v = it[1], time = it[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        dis[0] = 0;
        ways[0] = 1;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [distance, node] = pq.top();
            pq.pop();

            if (distance > dis[node]) continue;

            for (auto& [adjNode, adjTime] : adj[node]) {
                long long newDist = distance + adjTime;

                if (newDist < dis[adjNode]) {
                    dis[adjNode] = newDist;
                    pq.push({newDist, adjNode});
                    ways[adjNode] = ways[node];
                }
                else if (newDist == dis[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};
