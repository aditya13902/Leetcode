class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        priority_queue<int>pq;
        int i=0;
        int cnt=0;
        for(auto ele:flips){
            pq.push(ele);
            i++;
            if(pq.size()==i && pq.top()==i) cnt++;
        }
        return cnt;
    }
};