class Solution {
public:
    int helper(vector<int>&nums,int l,int r,int k){
        int pivot=nums[r];
        int lft=l;
        for(int i=l;i<r;i++){
            if(nums[i]<=pivot){
                swap(nums[i],nums[lft]);
                lft++;
            }
        }
        swap(nums[lft],nums[r]);
        if(lft==k) return nums[lft];
        if(lft>k){
            return helper(nums,l,lft-1,k);
        }
        else{
            return helper(nums,lft+1,r,k);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        k=n-k;
        return helper(nums,0,nums.size()-1,k);
    }
};