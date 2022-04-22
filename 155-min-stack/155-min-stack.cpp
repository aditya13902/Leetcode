class MinStack {
public:
    stack<int>st;
    multiset<int>ms;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        ms.insert(val);
    }
    
    void pop() {
        int top=st.top();
        auto it=ms.find(top);
        ms.erase(it);
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return *(ms.begin());
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