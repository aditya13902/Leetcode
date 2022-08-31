class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        for(auto ele:tasks){
            mp[ele]++;
        }
        priority_queue<int>pq;
        for(auto it:mp){
            pq.push(it.second);
        }
        queue<pair<int,int>>q;
        int t=0;
        while(pq.size() || q.size()){
            if(q.size()){
                if(t>q.front().second){
                    pq.push(q.front().first);
                    q.pop();
                }
            }
            if(pq.size()){
                auto curr=pq.top();
                pq.pop();
                curr--;
                if(curr){
                    q.push({curr,t+n});
                }
                // q.push({pq.top()-1})
            }
            t++;
        }
        return t;
    }
};