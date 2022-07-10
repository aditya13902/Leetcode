class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int>pq;
        for(auto ele:amount){
            if(ele==0) continue;
            pq.push(ele);
        }
        int cnt=0;
        while(pq.size()>1){
            int top1=pq.top();
            pq.pop();
            int top2=pq.top();
            pq.pop();
            cnt++;
            top1--;
            top2--;
            if(top2){
                pq.push(top2);
            }
            if(top1){
                pq.push(top1);
            }
        }
        if(pq.size()){
            cnt+=pq.top();
        }
        
        return cnt;
    }
};