class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        for(int i=0;i<nums.size();){
            if(nums[nums[i]-1]==nums[i]){
                i++;
            }
            else{
                swap(nums[nums[i]-1],nums[i]);
            }
        }
        vector<int>vec;
        for(int i=0;i<nums.size();i++){
            if(nums[i]-1!=i){
                vec.push_back(nums[i]);
            }
        }
        return vec;
    }
};