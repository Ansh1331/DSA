class Solution {
public:
    void helper(int index, int currentSum, const vector<int>& candidates, int target,
                vector<vector<int>>& res, vector<int>& temp) {
        if (currentSum == target) {
            res.push_back(temp);
            return;
        }

        for (int i = index; i < candidates.size(); ++i) {
            // Skip duplicates
            if (i > index && candidates[i] == candidates[i - 1]) continue;

            if (currentSum + candidates[i] > target) break;

            temp.push_back(candidates[i]);
            helper(i + 1, currentSum + candidates[i], candidates, target, res, temp);
            temp.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end()); // sort to handle duplicates
        helper(0, 0, candidates, target, res, temp);
        return res;
    }
};
