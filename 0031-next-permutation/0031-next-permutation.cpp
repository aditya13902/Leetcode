class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx=-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx=i;
                break;
            }
        }
        if(idx==-1){
            reverse(nums.begin(),nums.end());
        }
        else{
            reverse(nums.begin()+idx+1,nums.end());
            for(int i=idx+1;i<nums.size();i++){
                if(nums[idx]<nums[i]){
                    swap(nums[idx],nums[i]);
                    return;
                }
            }
        }
    }
};
// 2 4 1 3