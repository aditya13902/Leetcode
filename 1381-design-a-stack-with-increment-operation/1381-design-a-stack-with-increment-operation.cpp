class CustomStack {
public:
    int siz;
    stack<int>st;
    unordered_map<int,int>mp;
    CustomStack(int maxSize) {
        siz=maxSize;
    }
    
    void push(int x) {
        if(st.size()<siz){
            st.push(x);
        }
    }
    
    int pop() {
        if(st.size()==0) return -1;
        if(mp.find(st.size())!=mp.end()){
            auto curr=st.top();
            int val=mp[st.size()];
            mp[st.size()-1]+=val;
            mp[st.size()]=0;
            st.pop();
            return curr+val;
        }
        else{
            auto curr=st.top();
            st.pop();
            return curr;
        }
    }
    
    void increment(int k, int val) {
        int n=st.size();
        mp[min(n,k)]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */