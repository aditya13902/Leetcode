class Solution {
public:
    int quickselect(vector<int>& nums,int l,int r,int k){
        
        int pivot=nums[r];
        int idx=l;
        for(int i=l;i<r;i++){
            if(nums[i]<=pivot){
                swap(nums[i],nums[idx]);
                idx++;
            }
        }
        swap(nums[r],nums[idx]);
        if(idx<k) return quickselect(nums,idx+1,r,k);
        else if(idx>k) return quickselect(nums,l,idx-1,k);
        else return nums[idx];
        
    }
    int findKthLargest(vector<int>& nums, int k) {
        k=nums.size()-k;
        return quickselect(nums,0,nums.size()-1,k);
    }
};