class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto it=lower_bound(nums.begin(),nums.end(),target);// gives the iterator whose smallest value which is >=target
        // if(it!=nums.end() && *it==target){
        //     return it-nums.begin();
        // }
        return it-nums.begin();
    }
};