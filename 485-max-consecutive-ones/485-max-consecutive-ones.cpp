class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=-1;
        int ans=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]==0){
                i=j;
            }
            else{
                ans=max(j-i,ans);
            }
        }
        return ans;
    }
};