class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=0;
        int ans=INT_MIN;
        for(auto ele:nums){
            curr+=ele;
            ans=max(ans,curr);
            if(curr<0){
                curr=0;
            }
        }
        return ans;
    }
};