class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int idx=0;
        while(idx<nums.size()){
            if(nums[idx]==idx+1){
                idx++;
            }
            else{
                if(nums[nums[idx]-1]==nums[idx]){
                    return nums[idx]; 
                }
                swap(nums[idx],nums[nums[idx]-1]);
            }
        }
        return -1;
    }
};