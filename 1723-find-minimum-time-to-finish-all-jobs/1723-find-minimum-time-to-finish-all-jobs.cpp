class Solution {
public:
    int ans = INT_MAX;

    void dfs(vector<int>& jobs, vector<int>& workers, int idx) {
        if (idx == jobs.size()) {
            ans = min(ans, *max_element(workers.begin(), workers.end()));
            return;
        }
        
        for (int i = 0; i < workers.size(); i++) {
            if (workers[i] + jobs[idx] >= ans) continue; // prune
            workers[i] += jobs[idx];
            dfs(jobs, workers, idx + 1);
            workers[i] -= jobs[idx];
            if (workers[i] == 0) break; // avoid symmetric states
        }
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.rbegin(), jobs.rend()); // big jobs first
        vector<int> workers(k, 0);
        dfs(jobs, workers, 0);
        return ans;
    }
};
