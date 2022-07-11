class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>mp;
        priority_queue<int>pq;
        for(auto ch:s){
            mp[ch]++;
        }
        for(auto it:mp){
            pq.push(it.second);
        }
        int cnt=0;
        while(pq.size()>1){
            int t1=pq.top();
            pq.pop();
            int t2=pq.top();
            pq.pop();
            if(t1==t2){
                cnt++;
                t2--;
                if(t1) pq.push(t1);
                if(t2) pq.push(t2);
            }
            else{
                pq.push(t2);
            }
        }
        return cnt;
    }
};