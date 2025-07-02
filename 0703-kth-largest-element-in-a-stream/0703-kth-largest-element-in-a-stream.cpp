class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int size;

    KthLargest(int k, vector<int>& arr) {
        pq=priority_queue<int,vector<int>,greater<int>> ();
        size=k;
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
            while(pq.size() > k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size() > size){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */