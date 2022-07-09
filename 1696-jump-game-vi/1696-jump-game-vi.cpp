class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int>dp(size(nums),0);
        multiset<int>st;
        dp[0]=nums[0];
        st.insert(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(i>k){
                st.erase(st.find(dp[i-k-1]));
            }
            dp[i]=*(--st.end())+nums[i];
            st.insert(dp[i]);
        }
        return dp[nums.size()-1];
    }
};