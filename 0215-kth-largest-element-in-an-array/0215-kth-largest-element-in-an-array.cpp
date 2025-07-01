class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        priority_queue<int, vector<int>,greater<int>> minh;

        for(int i=0;i<arr.size();i++){
            minh.push(arr[i]);

            while(minh.size() > k){
                minh.pop();
            }
        }
        return minh.top();
    }
};