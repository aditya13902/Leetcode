class MyCalendarThree {
public:
    map<int,int>mp;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int ans=0;
        int curr=0;
        for(auto it:mp){
            curr+=it.second;
            ans=max(ans,curr);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */