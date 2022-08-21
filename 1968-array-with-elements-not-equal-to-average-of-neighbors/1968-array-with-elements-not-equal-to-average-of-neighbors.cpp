class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>arr(nums.size());
        int l=0;
        for(int i=0;l<nums.size();l+=2){
            arr[l]=nums[i++];
        }
        int r=1;
        for(int i=nums.size()-1;r<nums.size();r+=2){
            arr[r]=nums[i--];
        }
        return arr;
    }
};