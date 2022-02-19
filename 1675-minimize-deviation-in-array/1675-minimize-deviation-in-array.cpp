class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int>pq;
        int mn=INT_MAX;
        for(auto ele:nums){
            if(ele%2){
                ele=ele*2;
            }
            mn=min(ele,mn);
            pq.push(ele);
        }
        int diff=INT_MAX;
        while(pq.top()%2==0){
            int ele=pq.top();
            pq.pop();
            diff=min(diff,ele-mn);
            mn=min(ele/2,mn);
            pq.push(ele/2);
        }
        diff=min(diff,pq.top()-mn);
        return diff;
    }
};