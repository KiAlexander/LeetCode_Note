// https://leetcode-cn.com/problems/min-stack/
// 44ms,14.5MB
class MinStack {
public:
    stack<int> data;
    stack<int> minstack;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        data.push(x);
        if(minstack.empty() || x <= minstack.top()){
            minstack.push(x);
        }
    }
    
    void pop() {
        if(data.top() == minstack.top()){
            minstack.pop();
        }
        data.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */