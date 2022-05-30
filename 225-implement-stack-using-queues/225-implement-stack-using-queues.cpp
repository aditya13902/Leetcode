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
        q.push(x);
    }
    
    int pop() {
        if(q.size()==0){
            return -1;
        }
        rev();
        int ele=q.front();
        q.pop();
        rev();
        return ele;
    }
    
    int top() {
        if(q.size()==0){
            return -1;
        }
        rev();
        int ele=q.front();
        // q.pop();
        rev();
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