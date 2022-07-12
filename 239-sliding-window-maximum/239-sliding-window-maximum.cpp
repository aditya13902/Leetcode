class Solution {
public:
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int>st;
        for(int i=0;i<k;i++){
            st.insert(nums[i]);
        }
        int s=0;
        int e=k;
        vector<int>res;
        while(e<nums.size()){
            res.push_back(*(--st.end()));
            st.erase(st.find(nums[s]));
            st.insert(nums[e++]);
            s++;
        }
        res.push_back(*(--st.end()));
        return res;
    }
};