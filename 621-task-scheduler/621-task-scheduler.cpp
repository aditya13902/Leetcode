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
            t+=1;
            if(pq.size()){
                int curr=pq.top();
                pq.pop();
                curr--;
                if(curr) q.push({curr,t+n});
            }
            if(q.size()){
                if(q.front().second==t){
                    pq.push(q.front().first);
                    q.pop();
                }
            }
        }
        return t;
    }
};