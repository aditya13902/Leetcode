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
            if(pq.size() && curr==pq.top() && pq.top()!=0){
                int ele=pq.top();
                pq.pop();
                pq.push(ele-1);
                cnt++;
                pq.push(curr);
            }
        }
        return cnt;
    }
};