class MinStack {
    long mini = 1e15;
    stack<pair<long,long>> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        mini = min<long>(mini,val);
        st.push({val,mini});
    }
    
    void pop() {
        st.pop();
        if(!st.empty())
            mini = st.top().second;
        else
            mini = 1e16;
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
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