class MyStack {
public:
    queue<int>q;
    MyStack() {
        
    }
    void rev(){
        if(q.size()==0){
            return;
        }
        int ele=q.front();
        q.pop();
        rev();
        q.push(ele);
    }
    void push(int x) {
        rev();
        q.push(x);
        rev();
    }
    
    int pop() {
        int ele=q.front();
        q.pop();
        return ele;
    }
    
    int top() {
        int ele=q.front();
        return ele;
    }
    
    bool empty() {
        return q.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */