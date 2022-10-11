class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3) return false;
        vector<int>lft(nums.size(),INT_MAX);
        vector<int>rgt(nums.size(),INT_MIN);
        int curr=INT_MAX;
        for(int i=0;i<nums.size();i++){
            lft[i]=curr;
            curr=min(curr,nums[i]);
        }
        curr=INT_MIN;
        for(int i=nums.size()-1;i>=0;i--){
            rgt[i]=curr;
            curr=max(curr,nums[i]);
        }
        for(int i=1;i<=nums.size()-2;i++){
            if(lft[i]<nums[i] && rgt[i]>nums[i]){
                return true;
            }
        }
        return false;
        
    }
};