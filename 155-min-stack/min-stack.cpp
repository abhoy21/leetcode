class MinStack {
public:
    vector<int> v;
    vector<int> minv;
    MinStack() {
        
    }
    
    void push(int val) {
        v.push_back(val);
        if (minv.empty()) {
            minv.push_back(val);
        } else {
            minv.push_back(min(val, minv.back()));
        }
    }
    
    void pop() {
        v.pop_back();
        minv.pop_back();
    }
    
    int top() {
        return v.back();
    }
    
    int getMin() {
        return minv.back();
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