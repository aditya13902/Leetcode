class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto ele:stones){
            pq.push(ele);
        }
        while(pq.size()>=2){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            if(x!=y){
                if(x>y){
                    pq.push(x-y);
                }
                else{
                    pq.push(y-x);
                }
            }
        }
        if(pq.size()==0){
            return 0;
        }
        return pq.top();
    }
};