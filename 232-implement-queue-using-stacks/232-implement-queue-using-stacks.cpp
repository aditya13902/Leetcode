class MyQueue {
public:
    stack<int>s;
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        int data=s.top();
        s.pop();
        if(s.size()==0){
            return data;
        }
        int ans=pop();
        s.push(data);
        return ans;
    }
    
    int peek() {
        if(s.size()==1){
            int val=s.top();
            return val;
        }
        int data=s.top();
        s.pop();
        int ans=peek();
        s.push(data);
        return ans;
    }
    
    bool empty() {
        return s.size()==0;
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