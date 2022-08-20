class StockSpanner {
public:
    stack<pair<int,int>>st;
    int i;
    StockSpanner() {
        i=0;
    }
    
    int next(int price) {
        while(st.size() && st.top().first<=price){
            st.pop();
        }
        int ans=1;
        if(st.size()){
            ans=i-st.top().second;
        }
        else{
            ans=i+1;
        }
        st.push({price,i++});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */