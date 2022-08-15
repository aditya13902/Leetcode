class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>q;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(i>=k){
                ans.push_back(nums[q.front()]);
            }
            if(q.size() && q.front()<=i-k){
                q.pop_front();
            }
            while(q.size() && nums[q.back()]<=nums[i]){
                q.pop_back();
            }
            q.push_back(i);
        }
        ans.push_back(nums[q.front()]);
        return ans;
    }
};