class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0;
        int j=nums.size()-1;
        while(i<=j){
            int m=i+(j-i)/2;
            if(nums[m]==target) return m;
            else if(nums[m]>=nums[i]){
                if(target>nums[m] || target<nums[i]){
                    i=m+1;
                }
                else{
                    j=m-1;
                }
            }
            else{
                if(nums[m]>target || target>=nums[i]){
                    j=m-1;
                }
                else i=m+1;
            }
        }
        return -1;
    }
};