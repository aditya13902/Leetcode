class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<k;i++){
            pq.push({nums[i],i});
        }
        int e=k;
        vector<int>res;
        while(e<nums.size()){
            auto curr=pq.top();
            res.push_back(curr.first);
            while(pq.size() && pq.top().second<=e-k){
                pq.pop();
            }
            pq.push({nums[e],e});
            e++;
        }
        while(pq.top().second<e-k) pq.pop();
        res.push_back(pq.top().first);
        return res;
    }
};