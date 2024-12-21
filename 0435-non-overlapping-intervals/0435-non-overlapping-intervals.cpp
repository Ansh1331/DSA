class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end(), compare);

        int res = 0;
        int prevEnd = arr[0][1]; // Initialize with the end time of the first interval

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i][0] < prevEnd) {
                // Overlap detected, increment removal count
                res++;
            } else {
                // Update the end time of the last non-overlapping interval
                prevEnd = arr[i][1];
            }
        }
        return res;
    }
};
