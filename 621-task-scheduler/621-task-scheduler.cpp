class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>pq;
        unordered_map<int,int>mp;
        for(auto ele:tasks){
            mp[ele]++;
        }
        for(auto it:mp){
            pq.push(it.second);
        }
        queue<pair<int,int>>q;
        int t=0;
        while(pq.size() || q.size()){
            if(pq.size()){
                int curr=pq.top();
                pq.pop();
                curr--;
                if(curr) q.push({curr,t+n});
                
            }
            if(q.size() && q.front().second==t){
                auto top=q.front();
                q.pop();
                pq.push(top.first);
            }
            t++;
        }
        return t;
    }
};