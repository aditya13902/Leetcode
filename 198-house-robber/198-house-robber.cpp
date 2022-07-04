class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size());
        int prev2=0;
        int prev1=nums[0];
        for(int i=1;i<nums.size();i++){
            int curr=max(prev1,nums[i]+prev2);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};