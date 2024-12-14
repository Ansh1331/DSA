#include<stack>

class MinStack {
private:
    stack<int> mainstack, minstack;
public:
    MinStack() {}
    
    void push(int val) {
        if(minstack.empty() || val<=minstack.top()){
            minstack.push(val);
        }
        mainstack.push(val);
    }
    
    void pop() {
        if(minstack.top()==mainstack.top()){
            minstack.pop();
        }
        mainstack.pop();
    }
    
    int top() {
        return mainstack.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */