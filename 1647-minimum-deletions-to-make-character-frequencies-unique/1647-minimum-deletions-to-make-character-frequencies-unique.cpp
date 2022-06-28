class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>mp;
        for(auto ch:s){
            mp[ch]++;
        }
        priority_queue<int>pq;
        for(auto it:mp){
            pq.push(it.second);
        }
        int cnt=0;
        while(pq.size()){
            int curr=pq.top();
            pq.pop();
            while(pq.size() && curr==pq.top()){
                int ele=pq.top();
                pq.pop();
                ele--;
                if(ele>0){
                    pq.push(ele);
                }
                cnt++;
            }
        }
        return cnt;
    }
};