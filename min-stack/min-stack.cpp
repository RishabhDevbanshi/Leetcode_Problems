#define ll long long
class MinStack {
    ll mn = -1;
    stack<ll> st;
public:
    /** initialize your data structure here. */
    MinStack() {
        mn = -1;
        while(!st.empty()) st.pop();
    }
    
    void push(int x) {
        if(st.empty())
        {
            st.push(x);
            mn = x;
        }
        else if(x >= mn)
        {
            st.push(x);
        }
        else
        {
            ll val = (ll)2*x - mn;
            mn = x;
            st.push(val);
        }
    }
    
    void pop() {
        if(st.empty()) return;
        else if(st.size() == 1)
        {
            mn = -1;
            st.pop();
        }
        else if(st.top() < mn)
        {
            mn = 2*mn - st.top();
            st.pop();
        }
        else
        {
            st.pop();
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        else if(st.top() < mn)
        {
            return mn;
        }
        else return st.top();
    }
    
    int getMin() {
        return st.empty() ? -1 : mn;
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