class Solution {
public:
    int cnt=0;
    void merge(vector<int>&nums,int l,int m,int r){
        // vector<int>tmp(r-l+1);
        int i=l;
        int j=m+1;
        // int k=0;
        while(i<=m && j<=r){
            if((long long)nums[i]>(long long ) 2* nums[j]){
                // tmp[k++]=nums[j++];
                cnt+=(m-i+1);
                j++;
            }
            else{
                // tmp[k++]=nums[i++];
                i++;
            }
        }
        sort(nums.begin() + l, nums.begin() + r + 1);
    }
    void mergesort(vector<int>&nums,int l,int r){
        if(l<r){
            int m=l+(r-l)/2;
            mergesort(nums,l,m);
            mergesort(nums,m+1,r);
            merge(nums,l,m,r);
        }
    }
    int reversePairs(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return cnt;
    }
};