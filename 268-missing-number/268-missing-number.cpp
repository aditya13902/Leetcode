class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res=nums.size();
        int i=0;
        for(auto ele:nums){
            res^=ele;
            res^=i;
            i++;
        }
        return res;
    }
};