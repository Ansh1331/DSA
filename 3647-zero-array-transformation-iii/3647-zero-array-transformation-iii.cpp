class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int sz = queries.size();
        sort(queries.begin(), queries.end());
        vector<int> dif(n + 1);
        int sum = 0;
        int j = 0;
        priority_queue<int> pq;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            while (j < sz && queries[j][0] <= i) {
                pq.push(queries[j][1]);
                j++;
            }

            while (sum + dif[i] < nums[i]) {
                if (pq.empty()) {
                    return -1;
                }

                int a = pq.top();
                pq.pop();
                if (a >= i) {
                    dif[i]++;
                    dif[a + 1]--;
                    cnt++;
                }
            }

            sum += dif[i];
        }

        return sz-cnt;
    }
};
