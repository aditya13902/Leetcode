class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        while(l<r){
            int m=(l+r+1)/2;
            if(nums[m]<nums[m-1]){
                r=m-1;
            }
            else{
                l=m;
            }
        }
        return l;
    }
};