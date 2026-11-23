class MinStack {
private:
    vector<int> regStack;
    vector<int> minStack;
public:
    MinStack() {
        regStack = {};
    }
    
    void push(int val) {
        regStack.push_back(val);
        if (minStack.empty() || val <= minStack.back()) {
            minStack.push_back(val);
        }
    }
    
    void pop() {
        if (regStack.back() == minStack.back()) {
            minStack.pop_back();
        }
        regStack.pop_back();
    }
    
    int top() {
        return regStack.back();
    }
    
    int getMin() {
        return minStack.back();
    }
};
