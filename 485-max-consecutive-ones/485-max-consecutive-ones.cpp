class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0;
        int ans=0;
        for(auto ele:nums){
            if(ele==0){
                cnt=0;
            }
            else{
                cnt++;
            }
            ans=max(cnt,ans);
        }
        return ans;
    }
};