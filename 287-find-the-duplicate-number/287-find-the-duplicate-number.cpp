class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(auto ele:nums){
            int i=abs(ele);
            if(nums[i-1]<0){
                return i;
            }
            nums[i-1]*=-1;
        }
        return -1;
    }
};