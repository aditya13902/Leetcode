class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();){
            int idx=nums[i]-1;
            if(idx!=i){
                if(nums[idx]==nums[i]) return nums[i];
                swap(nums[idx],nums[i]);
            }
            else{
                i++;
            }
        }
        return nums.size();
    }
};