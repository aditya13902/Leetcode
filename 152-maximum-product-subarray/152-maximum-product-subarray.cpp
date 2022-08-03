class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curr=1;
        int ans=INT_MIN;
        for(auto ele:nums){
            curr*=ele;
            ans=max(ans,curr);
            if(ele==0){
                curr=1;
            }
        }
        curr=1;
        for(int i=nums.size()-1;i>=0;i--){
            curr*=nums[i];
            ans=max(ans,curr);
            if(nums[i]==0) curr=1;
        }
        return ans;
    }
};