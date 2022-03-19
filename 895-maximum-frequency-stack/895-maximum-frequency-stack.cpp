class FreqStack {
public:
    unordered_map<int,int>freq;
    unordered_map<int,stack<int>>mp;
    int mx=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        mx=max(mx,freq[val]);
        mp[freq[val]].push(val);
    }
    
    int pop() {
        int val=mp[mx].top();
        mp[mx].pop();
        if(mp[mx].size()==0){
            mx--;
        }
        freq[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */