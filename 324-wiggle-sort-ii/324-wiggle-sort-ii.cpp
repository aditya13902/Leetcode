class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        priority_queue<int>pq;
        for(auto ele:nums) pq.push(ele);
        int i=1;
        while(pq.size()){
            if(i>=nums.size()){
                i=0;
                continue;
            }
            nums[i]=pq.top();
            pq.pop();
            i+=2;
        }
    }
};