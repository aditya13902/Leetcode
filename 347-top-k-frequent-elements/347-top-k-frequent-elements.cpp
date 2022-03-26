class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto ele:nums){
            mp[ele]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        vector<int>ans;
        while(k--){
            auto x=pq.top();
            pq.pop();
            ans.push_back(x.second);
        }
        return ans;
        
            
    }
};