class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    MedianFinder() {}
    
    void addNum(int num) {
        if(maxheap.empty() || num<maxheap.top()){
            maxheap.push(num);
        }
        else{
            minheap.push(num);
        }

        //maintain leftmax heap size >=right min heap
        if(maxheap.size() >minheap.size()+1 ){
            minheap.push(maxheap.top());
            maxheap.pop();
        } 
        else if(minheap.size()>maxheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        if(minheap.size() == maxheap.size()){
            return (double)(minheap.top()+maxheap.top())/2.0;
        }   
        return maxheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */