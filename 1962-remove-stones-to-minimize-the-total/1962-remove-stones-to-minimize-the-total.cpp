class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        int tot=0;
        for(auto pile:piles){
            pq.push(pile);
            tot+=pile;
        }
        while(k--){
            int curr=pq.top();
            pq.pop();
            tot-=(curr/2);
            curr=(curr+1)/2;
            pq.push(curr);
        }
        return tot;
    }
};