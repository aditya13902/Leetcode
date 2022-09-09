class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn=INT_MAX;
        for(auto ele:nums){
            mn=min(ele,mn);
        }
        int tot=0;
        for(auto ele:nums){
            tot+=(ele-mn);
        }
        return tot;
    }
};