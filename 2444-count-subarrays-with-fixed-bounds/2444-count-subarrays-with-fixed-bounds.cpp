class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        bool fmn=0;
        bool fmx=0;
        int strt=0;
        int min_idx=-1;
        int max_idx=-1;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minK || nums[i]>maxK){
                fmn=0;
                fmx=0;
                min_idx=i;
                max_idx=i;
                strt=i+1;
            }
            if(nums[i]==minK){
                fmn=1;
                min_idx=i;
            }
            if(nums[i]==maxK){
                fmx=1;
                max_idx=i;
            }
            if(fmn && fmx){
                ans+=(min(max_idx,min_idx)-strt+1);
            }
        }
        return ans;
    }
};