class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();){
            int idx=nums[i]-1;
            if(nums[idx]!=nums[i]){
                swap(nums[idx],nums[i]);
            }
            else{
                if(i!=idx){
                    return nums[i];
                }
                else{
                    i++;
                }
            }
        }
        return -1;
    }
};