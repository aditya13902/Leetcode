class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int siz;
    KthLargest(int k, vector<int>& nums) {
        for(auto ele:nums){
            if(pq.size()<k){
                pq.push(ele);
            }
            else{
                if(ele>pq.top()){
                    pq.pop();
                    pq.push(ele);
                }
            }
        }
        siz=k;
    }
    
    int add(int ele) {
        if(pq.size()<siz){
            pq.push(ele);
        }
        else{
            if(ele>pq.top()){
                pq.pop();
                pq.push(ele);
            }
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */