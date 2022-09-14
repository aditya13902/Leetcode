class Solution {
public:
    int helper(vector<int>&nums,int l,int r,int k){
        if(l>r) return -1;
        int idx=l;
        int pivot=nums[r];
        for(int i=l;i<r;i++){
            if(nums[i]<=pivot){
                swap(nums[idx],nums[i]);
                idx++;
            }
        }
        swap(nums[idx],nums[r]);
        if(idx==k){
            return nums[idx];
        }
        if(idx>k){
            return helper(nums,l,idx-1,k);
        }
        return helper(nums,idx+1,r,k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        k=nums.size()-k;
        return helper(nums,0,nums.size()-1,k);
    }
};