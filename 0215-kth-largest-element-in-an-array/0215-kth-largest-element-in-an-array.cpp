class Solution {
public:
    int helper(vector<int>&nums,int s,int e,int k){
        if(s>e) return -1;
        int idx=s;
        int piv=nums[e];
        for(int i=s;i<e;i++){
            if(nums[i]<=piv){
                swap(nums[i],nums[idx]);
                idx++;
            }
        }
        swap(nums[idx],nums[e]);
        if(idx==k){
            return nums[idx];
        }
        else if(idx<k){
            return helper(nums,idx+1,e,k);
        }
        else{
            return helper(nums,s,idx-1,k);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        k=nums.size()-k;
        return helper(nums,0,nums.size()-1,k);
    }
};