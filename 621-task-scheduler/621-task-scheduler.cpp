class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int,int>mp;
        priority_queue<int>pq;
        for(auto ele:tasks){
            mp[ele]++;
        }
        for(auto it:mp){
            pq.push(it.second);
        }
        queue<pair<int,int>>q;
        int t=0;
        while(q.size() || pq.size()){
            t+=1;
            if(pq.size()){
                auto ele=pq.top();
                pq.pop();
                ele--;
                if(ele){
                    q.push({ele,t+n});
                }
            }
            if(q.size() && q.front().second==t){
                pq.push(q.front().first);
                q.pop();
            }
        }
        return t;
        
    }
};