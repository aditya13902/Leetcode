class Solution {
public:
    bool canJump(vector<int>& nums) {
        int currmx=0;
        for(int i=0;i<nums.size();i++){
            if(i>currmx){
                return false;
            }
            currmx=max(currmx,i+nums[i]);
        }
        return true;
    }
};