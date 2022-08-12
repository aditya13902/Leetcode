class Solution {
public:
    int jump(vector<int>& nums) {
        int prev=0;
        int curr=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(prev<i){
                if(curr>=i){
                    prev=curr;
                    cnt++;
                }
                else{
                     return -1;
                }
            }
            curr=max(curr,i+nums[i]);
        }
        return cnt;
    }
};