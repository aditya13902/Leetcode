class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx=0;
        // sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(idx==0 || nums[idx-1]!=nums[i]){
                nums[idx++]=nums[i];
            }
        }
        return idx;
    }
};