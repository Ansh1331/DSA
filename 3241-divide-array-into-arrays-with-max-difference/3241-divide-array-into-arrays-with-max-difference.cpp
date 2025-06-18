class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& arr, int k) {
        vector<vector<int>> res;
        int n = arr.size();
        if (n % 3 != 0) return res; 

        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; i += 3) {
            int smallest = arr[i];
            int largest = arr[i + 2];
            if (largest - smallest > k) return {};  

            res.push_back({arr[i], arr[i + 1], arr[i + 2]});
        }
        return res;
    }
};
