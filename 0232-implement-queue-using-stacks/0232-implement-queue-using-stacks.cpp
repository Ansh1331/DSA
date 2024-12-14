#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> in_stack, out_stack;

    void transfer() {
        while (!in_stack.empty()) {
            out_stack.push(in_stack.top());
            in_stack.pop();
        }
    }
    
public:
    MyQueue() {}

    void push(int x) {
        in_stack.push(x);
    }

    int pop() {
        if (out_stack.empty()) {
            transfer();
        }
        int topElement = out_stack.top();
        out_stack.pop();
        return topElement;
    }

    int peek() {
        if (out_stack.empty()) {
            transfer();
        }
        return out_stack.top();
    }

    bool empty() {
        return in_stack.empty() && out_stack.empty();
    }
};
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */