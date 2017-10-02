//
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//
// push(x) -- Push element x onto stack.
//
//
// pop() -- Removes the element on top of the stack.
//
//
// top() -- Get the top element.
//
//
// getMin() -- Retrieve the minimum element in the stack.
//
//
//
//
// Example:
//
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin();   --> Returns -3.
// minStack.pop();
// minStack.top();      --> Returns 0.
// minStack.getMin();   --> Returns -2.
//
//


class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> real,smin;
    MinStack() {}
    void push(int x) {
        if (!smin.empty()) {
            if (x<smin.top()) {
                smin.push(x);
            }
            else {
                smin.push(smin.top());
            }
        }
        else {
            smin.push(x);
        }
        real.push(x);
    }
    
    void pop() {
        real.pop();
        smin.pop();
    }
    
    int top() {
        return real.top();
    }
    
    int getMin() {
        return smin.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
